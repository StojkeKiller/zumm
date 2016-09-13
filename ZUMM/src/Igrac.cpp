#include "Igrac.h"
#include "main.h"

Igrac::Igrac()
{
    usporenje_brojac = 1;
    usporenje = 200;
    poeni = 0;
    energija_kretanja=-5;
    pozicija_x =0;
    pozicija_y =0;
    energija = 200;
}
void Igrac :: kretanje_ai(void)
{

        if (target_x != pozicija_x)
        {
            if (target_x < pozicija_x)
                {
                    pozicija_x--;

                }
                else if (target_x> pozicija_x)
                {
                    pozicija_x++;

                }
        }
        if (target_y != pozicija_y)
        {
                if (target_y < pozicija_y)
                {
                    pozicija_y--;

                }
                else if (target_y > pozicija_y)
                {
                    pozicija_y++;

                }
            }

}
void Igrac::kretanje_igraca(int komanda)
{

    if(tip == ai)
    {
        usporenje_brojac++;
    }
    if(tip == ai && usporenje_brojac==usporenje)
    {
        usporenje_brojac=0;
        kretanje_ai();
        return;
    }

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
    if(pozicija_x> xmax)
    {
        pozicija_x = 0;
    }
    if(pozicija_y < 0)
    {
        pozicija_y = ymax;
    }
    if(pozicija_y> ymax)
    {
        pozicija_y= 0;
    }
    if(komanda != nista && komanda != pucanj_desno && komanda != pucanj_dole && komanda != pucanj_gore && komanda != pucanj_levo)
    {
        energija=energija + energija_kretanja;
    }

}
Igrac::~Igrac()
{
    //dtor
}
