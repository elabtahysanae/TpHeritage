#include <iostream>

using namespace std;

class Point
{
    int x,y;
public:
    public:
        Point(int a, int b) {
        x=a;
        y=b;

        }

    void initialise(int a, int b)
    {
        x=a;
        y=b;
    }
    void deplace(int a, int b)
    {
        x=x+a;
        y=y+b;
    }
    void affiche()
    {
        cout<<"Point : "<<x<<" - "<<y<<endl;
    }
};

class Point_Colore : public Point
{
    int couleur;
public :
    Point_Colore(int a, int b, int c):Point(a,b){
    couleur=c;
    }


    void colorer(int c)
    {
        couleur = c;
    }
    void affiche()
    {
        Point::affiche();
        cout<<"en couleur : "<<couleur<<endl;
    }
    void initialise(int a, int b, int c)
    {
        Point::initialise(a,b);
        couleur= c;
    }
};
int main()
{

    Point_Colore p(0,0,0);            // constructeur par défaut

    p.initialise(12, 27, 9);   // initialise tout
    p.affiche();
    p.deplace(10, 20);         // déplace
    p.affiche();
    p.colorer(7);              // change couleur
    p.affiche();
    return 0;
}
