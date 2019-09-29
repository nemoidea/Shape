#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace sf;
using namespace std;

void mainMenu();
void subMenu();
void Painting();
void drawTriange();
void drawRectangle();
//void fillVector(vector<Triangle>&);

//za База от данни
void input();

void CreateFile();
void generate() {
	/*FILE* f;
	if ((f = fopen("DB.bin", "w")) == NULL)
		cout << "Не може да се отвори файла: DB.bin!\n";
	else
		fclose(f);*/

}


class Triangle
{
//private:
	string name;
	float x1, x2, x3, y1, y2, y3;
	int shape_type;

public:
	Triangle() {}
	Triangle(int typee, string str_name,float k_x1, float k_x2, float k_x3, float k_y1, float k_y2, float k_y3 ) {
		typee = 1;
		shape_type = typee;
		name = str_name;
		x1 = k_x1;
		x2 = k_x2;
		x3 = k_x3;
		y1 = k_y1;
		y2 = k_y2;
		y3 = k_y3;
		
	}
	Triangle(string triangleInformation) {
		stringstream triangleStream(triangleInformation);
		triangleStream >> shape_type;
		triangleStream >> name;
		triangleStream >> x1;
		triangleStream >> x2;
		triangleStream >> x3;
		triangleStream >> y1;
		triangleStream >> y2;
		triangleStream >> y3;

	}
	~Triangle() {}

	void SetName(int c_name) { this->name = c_name;}
	int getType()const { return this->shape_type; }
	string GetName()const { return this->name; }

	float getx1()const {	return this->x1; }
	float getx2()const { return this->x2; }
	float getx3()const { return this->x3; }

	float gety1()const { return this->y1; }
	float gety2()const { return this->y2; }
	float gety3()const { return this->y3; }
	

	void setx1(float c_x1) {  this->x1= c_x1; }
	void setx2(float c_x2) {  this->x2= c_x2; }
	void setx3(float c_x3) {  this->x3= c_x3; }

	void sety1(float c_y1) {  this->y1= c_y1; }
	void sety2(float c_y2) {  this->y2= c_y2; }
	void sety3(float c_y3) {  this->y3= c_y3; }

	


};
//class TriangleList {
//public:
//	TriangleList(string filePath){
//		ifstream FILE(filePath);
//		string lineContents;
//		while (!FILE.eof()) {
//			getline(FILE, lineContents);
//			Triangle e(lineContents);
//			triangletr.push_back(e);
//		}
//		FILE.close();
//	}
//
//	vector<Triangle>triangletr;
//};
//class MyClass
//{
//private:
//	string ime;
//	int edges;
//	float x, y;
//	
//
//public:
//	MyClass();
//	MyClass(string str_ime, int br_edges, float f_x, float f_y) {
//		this->ime = str_ime;
//		this->edges = br_edges;
//		this->x = f_x;
//		this->y = f_y;
//	}
//	~MyClass();
//
//	void SetName(int str_name) { this->ime = str_name; }
//	string GetName()const { return this->ime; }
//
//};

class Rectangle {
	string name;
	float x1, x2, x3,x4, y1, y2, y3,y4;
	int shape_type;

public:
	Rectangle() {}
	Rectangle(int typee, string str_name, float k_x1, float k_x2, float k_x3,float k_x4, float k_y1, float k_y2, float k_y3,float k_y4) {
		typee = 2;
		shape_type = typee;
		name = str_name;
		x1 = k_x1;
		x2 = k_x2;
		x3 = k_x3;
		x4 = k_x4;
		y1 = k_y1;
		y2 = k_y2;
		y3 = k_y3;
		y4 = k_y4;

	}
	Rectangle(string rectangleInformation) {
		stringstream rectangleStream(rectangleInformation);
		rectangleStream >> shape_type;
		rectangleStream >> name;
		rectangleStream >> x1;
		rectangleStream >> x2;
		rectangleStream >> x3;
		rectangleStream >> x4;
		rectangleStream >> y1;
		rectangleStream >> y2;
		rectangleStream >> y3;
		rectangleStream >> y4;
	}
	~Rectangle() {}

	void SetName(int c_name) { this->name = c_name; }
	int getType()const { return this->shape_type; }
	string GetName()const { return this->name; }

	float getx1()const { return this->x1; }
	float getx2()const { return this->x2; }
	float getx3()const { return this->x3; }
	float getx4()const { return this->x4; }
	float gety1()const { return this->y1; }
	float gety2()const { return this->y2; }
	float gety3()const { return this->y3; }
	float gety4()const { return this->y4; }

	void setx1(float c_x1) { this->x1 = c_x1; }
	void setx2(float c_x2) { this->x2 = c_x2; }
	void setx3(float c_x3) { this->x3 = c_x3; }
	void setx4(float c_x4) { this->x4 = c_x4; }

	void sety1(float c_y1) { this->y1 = c_y1; }
	void sety2(float c_y2) { this->y2 = c_y2; }
	void sety3(float c_y3) { this->y3 = c_y3; }
	void sety4(float c_y4) { this->y4 = c_y4; }



};

class Circle {
private:
	int x, y;

public:

};

class Polygon {
private:
	int x, y;

public:

};


void drawTriange(float x1, float y1, float x2, float y2, float x3, float y3) {

	
	sf::RenderWindow window(sf::VideoMode(900, 500), "Shape Drawing", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	sf::ConvexShape tri;
	tri.setPosition(Vector2f(200.f, 50.f));
	tri.setPointCount(3);
	tri.setPoint(0, sf::Vector2f(x1, y1));
	tri.setPoint(1, sf::Vector2f(x2, y2));
	tri.setPoint(2, sf::Vector2f(x3, y3));
	tri.setFillColor(sf::Color::Magenta);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//std::cout <<"New window width: " <<evnt.size.width <<"New window higth: " <<evnt.size.height << std::endl;
				printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);

				break;
			}
		}
		window.clear();
		window.draw(tri);
		window.display();

	}
}

void CreateFile()
{
	ofstream myfile;
	myfile.open("data.bin", ios::binary);
	
	
}

void drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3,float x4,float y4) {


	sf::RenderWindow window(sf::VideoMode(900, 500), "Shape Drawing", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	sf::ConvexShape tri;
	tri.setPosition(Vector2f(200.f, 50.f));
	tri.setPointCount(4);
	tri.setPoint(0, sf::Vector2f(x1, y1));
	tri.setPoint(1, sf::Vector2f(x2, y2));
	tri.setPoint(2, sf::Vector2f(x3, y3));
	tri.setPoint(3, sf::Vector2f(x4, y4));
	tri.setFillColor(sf::Color::Magenta);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//std::cout <<"New window width: " <<evnt.size.width <<"New window higth: " <<evnt.size.height << std::endl;
				printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);

				break;
			}
		}
		window.clear();
		window.draw(tri);
		window.display();

	}
}



void fillVectorT(vector<Triangle>& newMyClass) {
	
	int shape_type=1;
	string name;
	float x1, x2, x3, y1, y2, y3;
	 
	cout << " Kolko triugulnice shte dobawite ";
	int broi_triugulnici;
	cin >> broi_triugulnici;
	
	for (int i = 0; i < broi_triugulnici; i++)
	{	cout << "Ime na triugulnic ";
		cin >> name;
		cout << "kordinata x1 ";
		cin >> x1;
		cout << "kordinata x2 ";
		cin >> x2;
		cout << "kordinata x3 ";
		cin >> x3;
		cout << "kordinata y1 ";
		cin >> y1;
		cout << "kordinata y2 ";
		cin >> y2;
		cout << "kordinata y3 ";
		cin >> y3;
		
		Triangle newTriangle(shape_type,name, x1, x2, x3, y1, y2, y3);
		newMyClass.push_back(newTriangle);
		ofstream outFile;
		outFile.open("data.bin", ios::app | ios::binary);
		outFile << newTriangle.getType() << ' ' << newTriangle.GetName() << ' ' << newTriangle.getx1() << ' ' << newTriangle.gety1() << ' ' << newTriangle.getx2() << ' ' << newTriangle.gety2()
			<< ' ' << newTriangle.getx3() << ' ' << newTriangle.gety3() <<endl;
		
	
		outFile.close();
		
	}
	
	cout << endl;

}

void fillVectorR(vector<Rectangle>& newMyRectangle) {

	int shape_type = 2;
	string name;
	float x1, x2, x3,x4, y1, y2, y3,y4;

	cout << " Kolko kvadrata shte dobawite ";
	int broi_kvadrata;
	cin >> broi_kvadrata;

	for (int i = 0; i < broi_kvadrata; i++)
	{
		cout << "Ime na kvadrat ";
		cin >> name;
		cout << "kordinata x1 ";
		cin >> x1;
		cout << "kordinata x2 ";
		cin >> x2;
		cout << "kordinata x3 ";
		cin >> x3;
		cout << "kordinata x4 ";
		cin >> x4;
		cout << "kordinata y1 ";
		cin >> y1;
		cout << "kordinata y2 ";
		cin >> y2;
		cout << "kordinata y3 ";
		cin >> y3;
		cout << "kordinata y4 ";
		cin >> y4;

		Rectangle newRectangle(shape_type, name, x1, x2, x3,x4, y1, y2, y3,y4);
		newMyRectangle.push_back(newRectangle);
		ofstream outFile;
		outFile.open("data.bin", ios::app | ios::binary);
		outFile << newRectangle.getType() << ' ' << newRectangle.GetName() << ' ' << newRectangle.getx1() << ' ' << newRectangle.gety1() << ' ' << newRectangle.getx2() << ' ' << newRectangle.gety2()
			<< ' ' << newRectangle.getx3() << ' ' << newRectangle.gety3() << ' ' << newRectangle.getx4()<< ' ' << newRectangle.gety4() << endl;


		outFile.close();

	}

	cout << endl;

}

void printVectorT(const vector<Triangle>& newMyClass) {
	vector<Triangle>myTriangle;
	unsigned int size = newMyClass.size();
	for (unsigned i = 0; i < size; i++)
		if (newMyClass[i].getType() == 1) {
			{
				cout << "Ime na triygynik: " << newMyClass[i].GetName() << endl;
				cout << "   x1 : " << newMyClass[i].getx1()
					<< "   y1 : " << newMyClass[i].gety1() << endl
					<< "   x2 : " << newMyClass[i].getx2()
					<< "   y2 : " << newMyClass[i].gety2() << endl
					<< "   x3 : " << newMyClass[i].getx3()
					<< "   y3 : " << newMyClass[i].gety3() << endl;


				system("pause");
			}
		}
}
void printVectorR(const vector<Rectangle>& newMyRectangle) {
	vector<Triangle>myRectangle;
	unsigned int size = newMyRectangle.size();
	for (unsigned i = 0; i < size; i++)
		if (newMyRectangle[i].getType() == 1) {
			{
				cout << "Ime na triygynik: " << newMyRectangle[i].GetName() << endl;
				cout << "   x1 : " << newMyRectangle[i].getx1()
					<< "   y1 : " << newMyRectangle[i].gety1() << endl
					<< "   x2 : " << newMyRectangle[i].getx2()
					<< "   y2 : " << newMyRectangle[i].gety2() << endl
					<< "   x3 : " << newMyRectangle[i].getx3()
					<< "   y3 : " << newMyRectangle[i].gety3() << endl
					<< "   x4 : " << newMyRectangle[i].getx4()
					<< "   y4 : " << newMyRectangle[i].gety4() << endl;


				system("pause");
			}
		}
}

void subMenu(bool t) {
	int choice;

	do {
		system("cls");
		if (t == true) {
			cout << "Created empty DateBase " << endl;
		}
		
		cout<<endl 
			 << "#########->> Dobavi <<-############\n"
			 << "### 1 - Triugulnik         ########\n"
			 << "### 2 - Pravoygulnik       ########\n"
			 << "### 3 - Okrujnost          ########\n"
			 << "### 4 - Mnogougulnik       ########\n"
			 << "### 5 - Nazad              ########\n"
			 << "###################################\n"
			 << "###################################\n"
			 << "--Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{//Adding Triangle shape in DataBase and show what is added

			vector<Triangle>myTriangle;
			fillVectorT(myTriangle);
			printVectorT(myTriangle);
		}
			break;
		case 2:
		{
			//code to make score for this game to count how many times u win the game
			vector<Rectangle>myRectangle;
			fillVectorR(myRectangle);
			printVectorR(myRectangle);

		}
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			mainMenu();
			break;
		}
		
	} while (choice != 0);
}
void mainMenu() {
	int choice;
	bool t=false;
	do {
		system("cls");
		
		
		cout << endl
			<< "###########->> Menu <<-################################\n"
			<< "### 1 - Suzdavane na prazna Baza ot Danni:          ###\n"
			<< "### 2 - Dobavqne na figura w Bazata   :             ###\n"
			<< "### 3 - Namirane na figura po ime :                 ###\n"
			<< "### 4 - Spravka po obshto lice na daden tip figura: ###\n"
			<< "### 5 - Spravka po perimetur po-golqmo ot           ###\n"
			<< "###      zadadeno ot potrebitelq                  ###\n"
			<< "### 6 - Vizualizaciq na figurite:                 ###\n"
			<< "### 7 - Premahwane na figura:                     ###\n"
			<< "#####################################################\n"
			<< "--Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			
			t = true;
			CreateFile();
			subMenu(t);

			break;
		case 2:
		{
			subMenu(t);
			
		}
		break;
		case 3:
		{
			std::ifstream ifs("data.bin", ios::in | ios::binary);

			std::string line;

			while (std::getline(ifs, line))
			{
				cout << line;
				system("pause");
			}
		}
			break;
		case 4:
			Painting();
			break;
		case 5:
			//Triangle triangle();
			break;
		case 6:
		{
			ifstream theFile("data.bin", ios::in | ios::binary);
			
			int shape_type;
			string name;
			float x1, x2, x3,x4, y1, y2, y3,y4;
			
				while (theFile >> shape_type >> name >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4) {
					/*if (shape_type == 1) {
						cout << shape_type << "  " << name << "  " << x1 << "  " << x2 << "  " << x3 << "  " << y1 << "  " << y2 << "  " << y3 << endl;
						drawTriange(x1, x2, x3, y1, y2, y3);
					}*/
					
						cout << shape_type << "  " << name << "  " << x1 << "  " << x2 << "  " << x3 << "  " << x4 << "  " << y1 << "  " << y2 << "  " << y3 << "  " << y4 << endl;
						drawRectangle(x1, x2, x3, x4, y1, y2, y3, y4);
					
				}
			
			
				//while (theFile >> shape_type >> name >> x1 >> x2 >> x3 >>x4 >> y1 >> y2 >> y3>>y4) {
				//	//if (shape_type == 1) {
				//		cout << shape_type << "  " << name << "  " << x1 << "  " << x2 << "  " << x3 << "  " << x4 << "  " << y1 << "  " << y2 << "  " << y3 << "  " << y4 << endl;
				//		drawRectangle(x1, x2, x3,x4, y1, y2, y3,y4);
				//	}
				//}
			
		}
			break;
		case 7:
			
			break;
		}
	} while (choice != 0);
}

int main()
{
	
	
	
	mainMenu();
	
	
	
return 0;
}

//void Painting();
void Painting() {

	sf::RenderWindow window(sf::VideoMode(900, 500), "Shape Drawing", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	shape.setFillColor(sf::Color::Red);
	CircleShape triangle;
	triangle.setRadius(123);
	triangle.setPointCount(6);
	triangle.setFillColor(sf::Color::Magenta);


	sf::ConvexShape love;

	love.setPosition(Vector2f(200.f, 50.f));

	love.setPointCount(14);

	love.setPoint(0, sf::Vector2f(300, 60));
	love.setPoint(1, sf::Vector2f(370, 32));
	love.setPoint(2, sf::Vector2f(430, 29));
	love.setPoint(3, sf::Vector2f(500, 60));
	love.setPoint(4, sf::Vector2f(520, 80));
	love.setPoint(5, sf::Vector2f(500, 130));
	love.setPoint(6, sf::Vector2f(410, 200));
	love.setPoint(7, sf::Vector2f(300, 250));
	love.setPoint(8, sf::Vector2f(190, 200));
	love.setPoint(9, sf::Vector2f(100, 130));
	love.setPoint(10, sf::Vector2f(80, 80));
	love.setPoint(11, sf::Vector2f(100, 60));
	love.setPoint(12, sf::Vector2f(130, 29));
	love.setPoint(13, sf::Vector2f(230, 32));

	love.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//std::cout <<"New window width: " <<evnt.size.width <<"New window higth: " <<evnt.size.height << std::endl;
				printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);

				break;
			}
		}
		window.clear();
		window.draw(triangle);
		window.draw(love);
		window.display();
	}
}


