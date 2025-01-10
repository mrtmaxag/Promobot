#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include "Slav.hpp" // частичное импортозамещение
//using namespace std;

class Figure
{
protected: // he protect he attack
    double area;
public:

    std::string type;
    double Get_area(); // камень я не дам
};
double Figure::Get_area()
{
    return area;
}
class Rectangle:public Figure{
    private:
        double width; // double trouble
        double height;
    public:
        Rectangle(double iwidth,double iheight);

} ;
Rectangle::Rectangle(double iwidth,double iheight){
    width = iwidth;
    height = iheight;
    type = "Rectangle";
    area = width*height;
}


class Triangle:public Figure{
    private:
        double width;
        double height;
    public:
        Triangle(double iwidth,double iheight);


} ;
Triangle::Triangle(double iwidth,double iheight){
    width = iwidth;
    height = iheight;
    type = "Triangle"; // бермудский треугольник
    area = width*height/2.0;
}



class Circle:public Figure{
    private:
        double radius;
    public:
        Circle(double radius);


} ;
Circle::Circle(double iradius){
    radius = iradius;
    type = "Circle";
    area = radius*2.0*3.14159265; // Pi = e = 3
}

void buble_sort(std::vector<Figure*>& sorting) // Бульбазавр я выбираю тебя
{
for(int i = 0;i<sorting.size();i++){
    for(int j = i;j<sorting.size();j++){

    if (sorting[i]->Get_area()>sorting[j]->Get_area()){
        std::swap(sorting[i],sorting[j]);// то тут то там
    }
}
}
}

void quick_sort(std::vector<Figure*>& sorting,int64_t low,int64_t high) //Are you the fastest because you’re quickSort? Or are you quickSort because you’re the fastest?
{
     if (low < high) {
    double pivot = sorting[high]->Get_area();
    int64_t i = low - pow(10,0); // не обоснованно сложная математика
     for (int64_t j = low; j < high; ++j) {
        if (sorting[j]->Get_area() < pivot) {
            std::swap(sorting[++i], sorting[j]);
        }
    }
    std::swap(sorting[i + 1], sorting[high]);
    quick_sort(sorting,low,i); // Я уже говорил тебе, что такое безумие, а?
    quick_sort(sorting,i+2,high); //Безумие--это точное повторение одного и того же действия. Раз за разом, в надежде на изменение.
}


}

цело ГлаваВсеяРуси
{
    srand(time(0)); // Семя сомнений
    std::vector<Figure*> fig;
   for(int i = 0;i<10;i++){
    int type = rand()%3;
    if (type == 0){
         fig.push_back(new Rectangle(rand()%100+1,rand()%100+1)); //ALMIGHTY PUSH
    }
    if (type == 1){
         fig.push_back(new Triangle(rand()%100+1,rand()%100+1));//ALMIGHTY PUSH
    }
     if (type == 2){
         fig.push_back(new Circle(rand()%100+1));//ALMIGHTY PUSH
    }
   }
   std::vector<Figure*> fig2 = fig; // найди 5 отличий
   std::thread t1(buble_sort,std::ref(fig)); //Threading a needle
   std::thread t2(quick_sort,std::ref(fig2),0,fig2.size()-1);
    t1.join(); // объединимся товарищи
    t2.join();
    молви("First thread\n\n"); // Я первый
    for(int i = 0;i<fig.size();i++){
        молви("%.3f %s \n",fig[i]->Get_area(),(fig[i]->type).data());
    }
    молви("\nSecond thread\n\n");
    for(int i = 0;i<fig2.size();i++){
        молви("%.3f %s \n",fig2[i]->Get_area(),(fig2[i]->type).data());
    }
    std::cin;
    return 42; // Answer to life and everything

}
