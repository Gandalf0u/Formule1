#ifndef FORMUL111_PISTE_H
#define FORMUL111_PISTE_H

class Piste {

public:
    Piste();
    void addLap();
    int getLap() const;
    void affichage() const;
    int getUsure() const;

private:
    int lap = 0;
    int usure = 0;
};

#endif //FORMUL111_PISTE_H


