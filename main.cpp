#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>

using namespace std;

vector< vector<int> > g; // Lista de Adjac�ncia

int inverte(int numero){
    int i = 0;
    while (numero > 0) {
        i *= 10;
        i += (numero % 10);
        numero /= 10;
    }
    return i;
}

int magic(int x){
    g[x].push_back(x+1);
    g[x].push_back(inverte(x));
}

int bfs(int inicio,int final)
{
    //para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de dist�ncia minima para alcan�ar o vertice.
    vector<int> p(g.size(), -1); // Vetor que armazena o pai de cada vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou n�o.

    queue<int> Q; // Fila que define a ordem de acesso aos vertices.

    // Inicializa��o
    cor[inicio] = true; // Define a cor do v�rtice raiz como acessado.
    d[inicio] = 0; // Define a dist�ncia da raiz para ela mesma como 0.

    Q.push(inicio); // Enfileira a raiz.

    // Enquanto a fila n�o estiver vazia.
    while(!Q.empty())
    {
        int u = Q.front(); // Define u como sendo o v�rtice na frente na fila.
        Q.pop(); // Desenfileira.
//        cout<<"vertice atual: "<<u<<endl;
        // Para todo vertice adjacente � "u".
        for(int i = 0; i < g[u].size(); i++)
        {
            // Se o vertice adjacente � "u" n�o tiver sido encontrado.
            if(cor[g[u][i]] == false)
            {
//                cout<<g[u][i]<<endl;
                Q.push(g[u][i]); // Enfileira o vertice adjacente.
                cor[g[u][i]] = true; // Define o vertice adjacente como encontrado.
                d[g[u][i]] = d[u]+1; // Define a distancia minima para alcan�ar o vertice.
                if(g[u][i]==final) return d[final];
            }
        }
    }

}

int main()
{
    int a,b;

    g.resize(100000);

    for(int i=0;i<g.size();i++)
    {
        magic(i);
    }
    int t;
    cin>>t;
    for(int i = 0; i<t; i++) {
        cin >> a >> b;

        cout << bfs(a, b)<<endl;
    }

    return 0;
}
