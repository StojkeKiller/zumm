#ifndef IGRAC_H
#define IGRAC_H


class Igrac
{
    public:
        Igrac();
        int pozicija_x;
        int pozicija_y;
        char izgled;
        int tip;
        void kretanje_igraca(int);
        int energija;
        int poeni;
        int energija_kretanja;
        virtual ~Igrac();

    protected:

    private:
};

#endif // IGRAC_H
