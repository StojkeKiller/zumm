#ifndef METAK_H
#define METAK_H


class Metak
{
    public:
        Metak();
        void kretanje();
        bool u_kretanju;
        void zvuk_metka();
        int pozicija_x;
        int pozicija_y;
        int smer;
        int razorna_moc;
        void ispali(int,int,int);
        virtual ~Metak();

    protected:

    private:
};

#endif // METAK_H
