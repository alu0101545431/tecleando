/*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"

void GRAFO::destroy() {
  for (unsigned i = 0; i < n; i++) {
    LS[i].clear();
    //A[i].clear();
    if (dirigido == 1) {
      LP[i].clear();
    };
  }
  LS.clear();
  LP.clear();
  //A.clear();
}

void GRAFO::build(char nombrefichero[85], int &errorapertura) {
  ElementoLista dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if (textfile.is_open()) {
    unsigned i, j, k;
    // leemos por conversion implicita el numero de nodos, arcos y el atributo
    // dirigido
    textfile >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;
    // los nodos internamente se numeran desde 0 a n-1
    // creamos las n listas de sucesores
    LS.resize(n);
    // predecesores si no es dirigido
    if (Es_dirigido()) {
      LP.resize(n);
    }
    // leemos los m arcos
    for (k = 0; k < m; k++) {
      textfile >> (unsigned &)i >> (unsigned &)j >> (int &)dummy.c;
      // damos los valores a dummy.j y dummy.c
      dummy.j = j - 1;
      // situamos en la posici�n del nodo i a dummy mediante push_back
      LS[i - 1].push_back(dummy);
      // pendiente de hacer un segundo push_back si es no dirigido. O no.
      if (!Es_dirigido() && (i - 1) != (j - 1)) {
        dummy.j = i - 1;
        dummy.c = dummy.c;
        LS[j - 1].push_back(dummy);

      }
      // pendiente la construcci�n de LP, si es dirigido
      if (Es_dirigido()) {
        dummy.j = i - 1;
        LP[j - 1].push_back(dummy);
      }
      // pendiente del valor a devolver en errorapertura
      //...
    }
  } else {
    errorapertura = true;
  }
}

GRAFO::~GRAFO() { destroy(); }

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
  build(nombrefichero, errorapertura);
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura) {
  // Limpiamos la memoria dinamica asumida en la carga previa, como el
  // destructor
  destroy();
  // Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  std::cout << "llamada constructor again" << std::endl;
  build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() {
  if (dirigido == 1) {
    return 1;
  };
  return 0;
}

void GRAFO::Info_Grafo() {
  std::cout << "[INFO]: GRAFO DIRIGIDO: " << (Es_dirigido() ? "SÍ" : "NO")
            << std::endl;
  std::cout << "[INFO]: ORDEN: " << n << std::endl;
  std::cout << "[INFO]: NÚMERO DE ARCOS: " << m << std::endl;
}

void Mostrar_Lista(vector<LA_nodo> L) {
  for (int nodo_adyacente = 0; nodo_adyacente < L.size(); ++nodo_adyacente) {
    std::cout << nodo_adyacente + 1;
  }
}

void GRAFO ::Mostrar_Listas(int l) {
  switch (l) {
    case 0:
      for (int nodo = 0; nodo < LS.size(); ++nodo) {
        std::cout << "[NODO " << nodo + 1 << "]: ";
        for (int nodo_sucesor = 0; nodo_sucesor < LS[nodo].size();
             ++nodo_sucesor) {
          std::cout << LS[nodo][nodo_sucesor].j + 1 << " ";
        }
        std::cout << std::endl;
      }
      break;
    case 1:
      for (int nodo = 0; nodo < LS.size(); ++nodo) {
        std::cout << "[NODO " << nodo + 1 << "]: ";
        for (int nodo_sucesor = 0; nodo_sucesor < LS[nodo].size();
             ++nodo_sucesor) {
          std::cout << LS[nodo][nodo_sucesor].j + 1 << " ";
        }
        std::cout << std::endl;
      }
      break;
    case -1:
      for (int nodo = 0; nodo < LP.size(); ++nodo) {
        std::cout << "[NODO " << nodo + 1 << "]: ";
        for (int nodo_predecesor = 0; nodo_predecesor < LP[nodo].size();
             ++nodo_predecesor) {
          std::cout << LP[nodo][nodo_predecesor].j + 1 << " ";
        }
        std::cout << std::endl;
      }
      break;
    default:
      break;
  }
}

void GRAFO::Mostrar_Matriz()  // Muestra la matriz de adyacencia, tanto los
                              // nodos adyacentes como sus costes
{}

void GRAFO::dfs_num(
    unsigned i, vector<LA_nodo> L, vector<bool> &visitado,
    vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum,
    unsigned &postnum_ind)  // Recorrido en profundidad recursivo con
                            // recorridos enum y postnum
{
  visitado[i] = true;
  prenum[prenum_ind++] =
      i;  // asignamos el orden de visita prenum que corresponde el nodo i
  for (unsigned j = 0; j < L[i].size(); j++)
    if (!visitado[L[i][j].j]) {
      dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
    };
  postnum[postnum_ind++] =
      i;  // asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad() {
  // creación e inicialización de variables y vectores
  int v_size = LS.size() - 1;
  vector<bool> visitado;
  vector<unsigned> prenum;
  unsigned prenum_ind = 0;
  vector<unsigned> postnum;
  unsigned postnum_ind = 0;
  unsigned nodo_inicial;

  visitado.resize(v_size);  // también basta con tomar n
  prenum.resize(v_size);
  postnum.resize(v_size);
  // solicitud al usuario del nodo inicial del recorrido en profundidad
  std::cout << "[INPUT]: Nodo de inicio del recorrido en profundidad > ";
  std::cin >> nodo_inicial;
  dfs_num(nodo_inicial - 1, LS, visitado, prenum, prenum_ind, postnum,
          postnum_ind);
  // mostrar en pantalla el preorden
  std::cout << "[INFO]: Preorden" << std::endl;
  for (int i = 0; i < prenum_ind; ++i) {
    std::cout << "[" << prenum[i] + 1 << "]"
              << " -> ";
  }
  std::cout << std::endl;
  // mostrar en pantalla el postorden
  std::cout << "[INFO]: PostOrden" << std::endl;
  for (int i = 0; i < postnum_ind; ++i) {
    std::cout << "[" << postnum[i] + 1 << "]"
              << " -> ";
  }
  std::cout << std::endl;
}

void GRAFO::bfs_num(
    unsigned i,         // nodo desde el que realizamos el recorrido en amplitud
    vector<LA_nodo> L,  // lista que recorremos, LS o LP; por defecto LS
    vector<unsigned> &pred,  // vector de predecesores en el recorrido
    vector<unsigned> &d)     // vector de distancias a nodo i+1
// Recorrido en amplitud con la construcci�n de pred y d: usamos la cola
{
  vector<bool> visitado;  // creamos e iniciamos el vector visitado
  visitado.resize(n, false);
  visitado[i] = true;

  pred.resize(n, 0);  // creamos e inicializamos pred y d
  d.resize(n, 0);
  pred[i] = i + 1;
  d[i] = 0;

  queue<unsigned> cola;  // creamos e inicializamos la cola
  cola.push(i);          // iniciamos el recorrido desde el nodo i+1

  while (!cola.empty())  // al menos entra una vez al visitar el nodo i+1 y
                         // contin�a hasta que la cola se vac�e
  {
    unsigned k = cola.front();  // cogemos el nodo k+1 de la cola
    cola.pop();                 // lo sacamos de la cola
    // Hacemos el recorrido sobre L desde el nodo k+1
    for (unsigned j = 0; j < L[k].size(); j++)
    // Recorremos todos los nodos u adyacentes al nodo k+1
    // Si el nodo u no est� visitado
    {
      if (!(visitado.at(L[k][j].j))) {
        // Lo visitamos
        visitado.at(L[k][j].j) = true;
        // Lo metemos en la cola
        cola.push(L[k][j].j);
        // le asignamos el predecesor
        pred[L[k][j].j] = k + 1;
        // le calculamos su etiqueta distancia
        d[L[k][j].j] = d[k] + 1;
      }
    };
    // Hemos terminado pues la cola est� vac�a
  };
}

void GRAFO::RecorridoAmplitud() {
  vector<unsigned> pred;
  vector<unsigned> d;
  int nodo_inicial;
  std::cout << "Digite el nodo del que quiere iniciar el recorrido [1 - " << n
            << "]: ";
  std::cin >> nodo_inicial;
  std::cout << "\n";
  bfs_num((nodo_inicial - 1), LS, pred, d);
  int d_max{0};

  for (int contador = 0; contador < n; contador++) {
    if (d[contador] > d_max) {
      d_max = d[contador];
    }
  }

  std::cout << "Nodos segun distancia al nodo inicial en numero de aristas\n";
  std::cout << "Distancia 0 aristas : " << nodo_inicial << endl;
  for (int contador = 1; contador <= d_max; ++contador) {
    std::cout << "Distancia " << contador << " aristas";
    for (int contador_2 = 0; contador_2 < n; contador_2++) {
      if (contador == d[contador_2]) {
        std::cout  << " : " << contador_2 + 1;
      }
    }
    std::cout << "\n";
  }

  cout << "La lista de predecesores es la siguiente:\n";
  for (int i = 0; i < n; ++i) {
    if (pred[i] == 0) {
      cout << "Predecesor del nodo " << i + 1 << " : -" << endl;
    } else {
      cout << "Predecesor del nodo " << i + 1 << " : " << pred.at(i) << endl;
    }
  }
}  // Construye un recorrido en amplitud desde un
   // nodo inicial
