#ifndef INTERPOLACION_H
#define INTERPOLACION_H


class Interpolacion
{
    public:
        Interpolacion();
        virtual ~Interpolacion();

        void setPosX(float x);
        void setPosY(float y);

        float getPosX();
        float getPosY();

    protected:

    private:
        float posX;
        float posY;

};

#endif // INTERPOLACION_H
