/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jhenny Cervera Vargas
 * Codigo: 20182841
 * Created on 29 de agosto de 2021, 04:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>        
using namespace std;
#define NOMBR 50
#define MAX 100

/*
 * ruc, nombreTien, fecha, tipoMov, codProd, nombreProd, cantProd, unidadMedprod
 */

void imprimirMov(int dd, int mm, int aa, int codProd, char* nombreProd, double cantProdDec,
        char *unidadMedprod) {


    cout.fill('0');

    cout << right << setw(2) << dd << '/' << setw(2) << mm << '/' << aa;
    cout.fill(' ');

    cout << setw(10) << ' ';
    cout.fill('0');
    cout << setw(8) << codProd;
    cout.fill(' ');
    cout<<setw(10)<<' '<<left<<setw(50)<<nombreProd;
    cout.precision(2);
    cout<<fixed<<left<<setw(10)<<cantProdDec<<unidadMedprod;
    
    cout << endl<<endl;
    
}

void leerMovimientos(int &ruc) {

    int dd, mm, aa, tipoMov, codProd;
    char aux, nombreProd[NOMBR], unidadMedprod[5];
    double cantProdDec;

    int flag = 0; //para saber que ha tenido algun movimiento valido
    while (1) {
        cin>>dd;
        if (cin.eof()) break;
        if (dd > 31) { //es un ruc 
            cin.clear();
            if (flag == 0) { //ningun mov es correcto
                //imprimir guion?    
            }
            ruc = dd;
            break;
        } else {
            cin >> aux >> mm >> aux >> aa>>tipoMov;
            int auxDig = tipoMov / 100;
            cin >> codProd >> nombreProd>>cantProdDec; //PREG si se debe validar si es decimal o entero  //si leo un double y es entero igual lo leee?
            if (cin.fail()) { //es el tipo de unidad
                cin.clear();
                cantProdDec = 1;
            }
            cin>>unidadMedprod;
            if (auxDig == 5 || auxDig == 3) { //se imprime todo el mov
                flag = 1;
                imprimirMov(dd, mm, aa, codProd, nombreProd, cantProdDec, unidadMedprod);
            }

        }
    }
}


void imprimirLinea(char c, int cant){
    cout.fill(c);
    cout<<setw(cant)<<c<<endl;
    cout.fill(' ');
}

void elaborarReporte() {

    //ifstream ArchMov("tiendas.txt", ios::in);

    cout << setw(40) << "REPORTE KARDEX" << endl;
    imprimirLinea('=', MAX);

    char nombreTien[NOMBR];
    int ruc;

    cin>>ruc;
    while (1) {
        if (cin.eof()) break;
        cin>>nombreTien;
        //imprimri ruc y nomber
        cout << left << setw(15) << ruc << nombreTien << endl;
        imprimirLinea('=', MAX);
        cout<<left<<setw(20)<<"FECHA"<<setw(10)<<"CODIGO"<<setw(25)<<"DESCRIPCION"<<setw(10)<<"CANTIDAD"<<"UNIDAD"<<endl;
        imprimirLinea('-', MAX);
        leerMovimientos(ruc);
        imprimirLinea('=', MAX);


    }

}

int main(int argc, char** argv) {

    elaborarReporte();

    return 0;
}

