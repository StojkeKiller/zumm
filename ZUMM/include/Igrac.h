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
        int target_x;
        int target_y;
        int energija;
        int poeni;
        int energija_kretanja;
        int usporenje_brojac;
        int usporenje;
        virtual ~Igrac();

    protected:

    private:
        void kretanje_ai(void);
};

#endif // IGRAC_H
