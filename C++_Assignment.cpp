#include <iostream>
#include <cmath>
using namespace std;
class baseMath
{
public:
    baseMath()
    { }
    bool isEven(int number)
    {
        return !(number%2);
    }
    int factorial(int n)
    {
        int result=1;
        for(int i=1;i<n+1;i++)
            result=result*i;
        return result;
    }

};

class advancedMath : public baseMath
{
public:
    advancedMath()
    { }
    double estimateEulerNumber(int loops)
    {
        double result=0;
        for(int i=0;i<loops+1;i++)
            result=result+1.0/factorial(i);
        return result;
    }
};

class centerPoint
{
private:
    int x;
    int y;
public:
    centerPoint()
    {}
    centerPoint(int x,int y)
        : x{x},y{y}
    { }
    double computeDist(centerPoint point)
    {
        return sqrt(double((point.x-this->x)*(point.x-this->x))+double((point.y-this->y)*(point.y-this->y)));
    }
};

class myShape
{
public:
    myShape()
    {}
    centerPoint point;
    virtual double computeArea()
    {
        return 0;
    }
    virtual double computeCicum()
    {
        return 0;
    }

    double computeDistance(myShape shape)
    {
        return this->point.computeDist(shape.point);
    }

    virtual ~myShape(){};
};

class mySquare : public myShape
{
private:
    double side;
public:
    mySquare(centerPoint point,double side)
    {
        this->point=point;
        this->side=side;
    }
    double computeArea()
    {
        return side*side;
    }
    double computeCircum()
    {
        return side*4;
    }
};

class myCircle : public myShape
{
private:
    double radius;
public:
    myCircle(centerPoint point,double radius)
    {
        this->point=point;
        this->radius=radius;
    }
    double computeArea()
    {
        return radius*radius*3.14;
    }
    double computeCircum()
    {
        return radius*2*3.14;
    }
};

class myRectangle : public myShape
{
private:
    double width;
    double height;
public:
    myRectangle(centerPoint point,double width,double height)
    {
        this->point=point;
        this->width=width;
        this->height=height;
    }
    double computeArea()
    {
        return width*height;
    }
    double computeCircum()
    {
        return 2*(width+height);
    }

};

int main()
{
    return 0;
}
