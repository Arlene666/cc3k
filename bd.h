#ifndef _BD_H_
#define _BD_H_

class BD : public Potion {
    public:
    BD();
    protected:
    void usedDefault(Player &p) override;
    void usedImpl(Drow &d) override;
};


#endif

