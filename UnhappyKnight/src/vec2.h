//
// Created by Housseini on 08/05/2024.
//

#ifndef UNHAPPYKNIGHT_VEC2_H
#define UNHAPPYKNIGHT_VEC2_H


class vec2 {
public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
    vec2(int px, int py):x(px),y(py){

    }
private:
    int x, y;


};


#endif //UNHAPPYKNIGHT_VEC2_H
