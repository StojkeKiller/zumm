#include "Igrac.h"
#include "main.h"

Igrac::Igrac()
{
    poeni = 0;
    energija_kretanja=-5;
    pozicija_x =0;
    pozicija_y =0;
    energija = 200;
}
void Igrac::kretanje_igraca(int komanda)
{
    if(komanda == desno)
    {
        pozicija_x++;
    }
    if(komanda == levo)
    {
        pozicija_x--;
    }
    if(komanda == gore)
    {
        pozicija_y--;
    }
    if(komanda == dole)
    {
        pozicija_y++;
    }
    if(pozicija_x < 0)
    {
        pozicija_x = xmax;
    }
    if(pozicija_x>= xmax)
    {
        pozicija_x = 0;
    }
    if(pozicija_y < 0)
    {
        pozicija_y = ymax;
    }
    if(pozicija_y>= ymax)
    {
        pozicija_y= 0;
    }

}
Igrac::~Igrac()
{
    //dtor
}
