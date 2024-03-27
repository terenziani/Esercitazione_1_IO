//esercizio di mappatura da un intervallo [1,5] all'intervallo [-1,2]


#include <iostream>
#include <fstream>

using namespace std;


//definisco la funzione che calcola il parametro m della retta y=m*x+q
double calcolam(double x0, double x1, double y0, double y1)
{
    double m;
    m=(y1-y0)/(x1-x0);
    return m;
}


//definisco la funzione che calcola il parametro q della retta y=m*x+q
double calcolaq(double m, double x, double y)
{
    double q;
    q = y-m*x;
    return q;
}



//definisco la funzione di mapping

double mapping(double x, double m, double q)
{
    double ris;
    ris= m*x + q;
    return ris;
}



int main()
{
    //dichiaro i file di input

    string filename("data.csv");

    ifstream ifs(filename);

    //dichiaro il file di output

    string filename2("result.csv");

    ofstream ofs(filename2);

    //controllo se i due file sono stati aperti correttamente

    if (! ofs.is_open())
    { cout<< "errore di apertura del file di output \n";
    }

    else if (! ifs.is_open())
    { cout << "errore di apertura del file input \n";
    }

    //se sono aperti correttamente svolgo le operazioni
    else
    {
        //richiamo le funzioni per calcolare m e q

        double m = calcolam(1,5,-1,2);
        double q = calcolaq(m,1,-1);

        //inizializzo somma e count
        double somma;
        somma=0;
        double count;
        count=0;



        ofs << "# N Mean \n";


        //finchè ho dati nel file di input
        while (! ifs.eof())
        {
            double x;
            ifs >> x;

            double newval = mapping(x,m,q);
            count++;
            somma += newval;

            double media;
            media = somma/count;

            ofs << count << " " << media << "\n";

        }
    }


    //chiudo i file

    ifs.close();
    ofs.close();


    return 0;
}
