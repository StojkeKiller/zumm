#ifndef METAK_H
#define METAK_H


class Metak
{
    public:
        Metak();
        kretanje();
        int pozicija_x;
        int pozicija_y;
        int razorna_moc;
        void ispali(int);
        virtual ~Metak();

    protected:

    private:
};

#endif // METAK_H
