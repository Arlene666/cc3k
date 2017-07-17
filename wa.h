#ifndef _WA_H_
#define _WA_H_


class WA : public Potion {
    public:
    WA();
    protected:
    void usedDefault(Player &p) override;
    void usedImpl(Drow &d) override;
};


#endif

