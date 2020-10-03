#include <iostream> 
#include <conio.h>
using namespace std;

//funcion que devuelve el numero que ira en cada posicion del triángulo 
int llenar_pos(int fila,int indice){
    if(fila==1)
        return 1;//en el pico del triángulo es 1     else{
        if(indice==0 ||indice==fila-1 )//en los costados del triángulo siempre es 1             
            return 1;
        else
            return llenar_pos(fila-1,indice-1)+llenar_pos(fila-1,indice);
    } 

//espacios para mostrar el triangulo adecuadamente 
void espacios_en_blanco(int n){
    if(n>0){
        cout<<" ";
        espacios_en_blanco(n-1);
    }
    else cout<<""; 
} 
void mostrar_pascal(int pos,int fila,int n,int esp,bool band){
    
    if(fila<=n){
        if(band==true){
         espacios_en_blanco(esp);
         band=false;
        }
        cout<<llenar_pos(fila,pos)<<" ";
        if(pos<fila-1)
            mostrar_pascal(pos+1,fila,n,esp,band);
        else{
            cout<<endl;
            band=true;
            mostrar_pascal(0,fila+1,n,esp-1,band);
        }
    }
    else {
        cout<<endl;
        band=true;
    } 
}
void triangulo_pascal(int filas){
   //empiza en la fila 1 y en el indice 0     
   //true es una bandera para los espacios en blanco     
   mostrar_pascal(0,1,filas,filas,true);
} 
int main(int argc, char** argv) {
    int filas;
    cout<<"ingrese filas:";
    cin>>filas;
    triangulo_pascal(filas);
    system("pause");
    return 0; 
}
