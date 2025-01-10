#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Figure
{
protected:
    double area;
public:

    std::string type;
    double Get_area();
};
double Figure::Get_area()
{
    return area;
}
class Rectangle:public Figure{
    private:
        double width;
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
    type = "Triangle";
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
    area = radius*2.0*3.14159265;
}

void buble_sort(std::vector<Figure*>& sorting)
{
for(int i = 0;i<sorting.size();i++){
    for(int j = i;j<sorting.size();j++){

    if (sorting[i]->Get_area()>sorting[j]->Get_area()){
        std::swap(sorting[i],sorting[j]);
    }
}
}

}

void quick_sort(std::vector<Figure*>& sorting,int64_t low,int64_t high)
{
     if (low < high) {
    double pivot = sorting[high]->Get_area();
    int64_t i = low - 1;
     for (int64_t j = low; j < high; ++j) {
        if (sorting[j]->Get_area() < pivot) {
            std::swap(sorting[++i], sorting[j]);
        }
    }
    std::swap(sorting[i + 1], sorting[high]);
    quick_sort(sorting,low,i);
    quick_sort(sorting,i+2,high);
}
}


int main()
{
    srand(time(0));
    std::vector<Figure*> fig;
   for(int i = 0;i<10;i++){
    int type = rand()%3;
    if (type == 0){
         fig.push_back(new Rectangle(rand()%100+1,rand()%100+1));
    }
    if (type == 1){
         fig.push_back(new Triangle(rand()%100+1,rand()%100+1));
    }
     if (type == 2){
         fig.push_back(new Circle(rand()%100+1));
    }

   }
   std::vector<Figure*> fig2 = fig;
   std::thread t1(buble_sort,std::ref(fig));
   std::thread t2(quick_sort,ref(fig2),0,fig2.size()-1);
    t1.join();
    t2.join();
    std::cout << "First thread\n";
    for(int i = 0;i<fig.size();i++){
        cout << fig[i]->Get_area()<< " " << fig[i]->type << endl;
    }
    cout << "Second thread\n";
    for(int i = 0;i<fig2.size();i++){
        std::cout << fig2[i]->Get_area()<< " " << fig2[i]->type << endl;
    }
    int k;
    std::cin >> k;
    return 0;

}
