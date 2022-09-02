#include<iostream>
#include<fstream>
using namespace std;
void superiores(float m[][5],int fil,float maux[][5])
{
    
    const long int superar=13000;
     for(int i=0;i<fil;i++){
        for (int j=0;j<5; j++){
            if(m[i][j]>superar){
                 maux[i][j]=m[i][j];
            }
        }
     }
}
void mostrarVS(string v[],int dim){
    for(int i=0;i<dim;i++){
        cout<<"ID "<< i<<"  "<<v[i]<<endl;
    }
}
void mostrarV(int v[],int dim){
    for(int i=0;i<dim;i++){
        cout<<"ID "<< i<<"  "<<v[i]<<endl;
    }
}
void mostrarM(float m[][5],int filas){
    for(int i=0;i<filas;i++){
        for (int j=0;j<5; j++){
            cout<<m[i][j]<<"                                       ";
        }
        cout<<endl;  
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

int main(){
const int CliFil=8;  //dimension de vectores de clietnes
const int Prodcol=5;  //dimension de vectores de productos
float cliente_producto [CliFil][Prodcol]{};  //matriz cliente-producto que almacena kilogramos totales
float cliente_productoKm[CliFil][Prodcol]{};  //matriz cliente-producto que almacena distancia total
int Entregas[Prodcol]{};  //contador de entregas
int entregasAux[Prodcol]{};  //contador de entregas auxiliar
string Nclientes[CliFil]{};  //vector que almacena nombre de clientes
string Nproductos[Prodcol]{};  //vector que almacena nombre de tipos de producto
string NproductosAux[Prodcol]{};  //vector auxiliar para no alterar el original
int icliente=0;  //indice de cliente
int iprod=0;  //indice de tipos de produtos
float kilos=0;  //variable para guardar datos de los kilos
float distancia=0;  //variable para guardar datos de la distancia recorrida 
float auxM[CliFil][Prodcol]{};  //matriz auxiliar 
int cliente_contador[CliFil]{};  //contador para determinar que cliente tiene la mayor cantidad de productos mayores a 130000kg
int iauxiliar=0;  //indice auxiliar;

/*leer e ingresar nombres de clientes y tipos de productos*/
ifstream archilec;
archilec.open("Nombres.txt");
if(!archilec){
    cout<<"Error al abrir archivo con nombres."<<endl;
    return 1;
}
for(int i=0;i<CliFil;i++){
    archilec>>Nclientes[i];
}
for(int i=0;i<Prodcol;i++){
    archilec>>Nproductos[i];
    
}
archilec.close();
/*cout<<"------------CLIENTES------------"<<endl;
mostrarVS(Nclientes,CliFil);*/
/*ccout<<"----------------"<<endl;
cout<<"------------PRODUCTOS------------"<<endl;
mostrarVS(Nproductos,Prodcol);
cout<<"----------------"<<endl;*/

/*carga de datos a las matrices y verctores*/

archilec.open("Datos.txt");
if(!archilec){
    cout<<"Error al abrir archivo con nombres."<<endl;
    return 1;
}
while (archilec>>icliente>>iprod>>kilos>>distancia)
{
 cliente_producto[icliente][iprod]=cliente_producto[icliente][iprod] + kilos;
 cliente_productoKm[icliente][iprod]=cliente_productoKm[icliente][iprod]+distancia;
 Entregas[iprod]++;
}
/*cout<<"------------MATRIZ KILOS------------"<<endl;
mostrarM(cliente_producto,CliFil);
cout<<"------------MATRIZ DISTANCIA------------"<<endl;
mostrarM(cliente_productoKm,CliFil);


/*------------PUNTO 1------------*/

superiores(cliente_producto,CliFil,auxM);
/*cout<<"------------MATRIZ QUE SUPEREN 13K POR CLIENTE------------"<<endl;
mostrarM(auxM,CliFil);*/
cout<<"Punto 1"<<endl;
cout<<"Listado por clientes, de los tipos de productos que superan los 13000KG acumulados."<<endl;
cout<<endl;
for(int i=0;i<CliFil;i++){
   cout<<"Cliente "<<Nclientes[i]<<": ";
   for(int j=0;j<Prodcol;j++){
    if(auxM[i][j]>0){
        cout<<"  "<<Nproductos[j];

     }
   }
   cout<<endl;
}
/*cout<<"------------PUNTO 2------------"<<endl;*/
for (int i = 0; i < CliFil; i++){
   for (int j = 0; j < Prodcol; j++){
        if(auxM[i][j]>0){
            cliente_contador[i]++;    
        }
    }
    if(cliente_contador[iauxiliar]<cliente_contador[i]){
        iauxiliar=i;
    }
}
/* cout<<"------------CANTIDAD DE TIPOS DE PRODUCTOS POR ID DE CLIENTE------------"<<endl;
mostrarV(cliente_contador,CliFil);
cout<<"------------"<<endl;*/
cout<<endl;
cout<<"Punto 2"<<endl;
cout<<"El cliente con mayor cantidad de tipos de productos es: "<<Nclientes[iauxiliar]<<" con "<<cliente_contador[iauxiliar]<<" tipos de productos."<<endl;
float temp=0;
for( int i=0;i<Prodcol;i++){
    NproductosAux[i]=Nproductos[i];
    entregasAux[i]=Entregas[i];
}
for (int i=0;i<Prodcol-1;i++){
 for(int j=0;j<Prodcol-1;j++){
       if(cliente_productoKm[iauxiliar][j]>cliente_productoKm[iauxiliar][j+1]){
        temp =cliente_productoKm[iauxiliar][j+1];
        cliente_productoKm[iauxiliar][j+1]=cliente_productoKm[iauxiliar][j];
        cliente_productoKm[iauxiliar][j]=temp;
        swap(NproductosAux[j+1],NproductosAux[j]);
        entregasAux[j+1]=Entregas[j];
        }
    }
}
for (int j = 0; j < Prodcol; j++){
    cout<<NproductosAux[j]<<":  "<<cliente_productoKm[iauxiliar][j]<<" Km recorridos. "<<endl; 
}
/*cout<<"------------PUNTO 3------------"<<endl;
cout<<"------------"<<endl;*/
/*cout<<"cantidad de entregas por producto"<<endl;
mostrarV(Entregas,Prodcol);*/
for(int j=4;j<Prodcol;j++){
   /* cout<<"------------ Km mayor------------"<<endl;
    cout<<cliente_productoKm[iauxiliar][j]<<endl;*/
    cout<<endl;
    cout<<"Punto 3"<<endl;
    cout<<"Para el tipo de producto "<<NproductosAux[j]<<" que tiene recorridos Km: "<<cliente_productoKm[iauxiliar][j]<<" se realizaron: "<<entregasAux[j]<<" entregas."<<endl;   
}
 return 0;
}