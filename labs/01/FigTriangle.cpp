// FigTriangle.cpp - Реализация функций, осуществляющих обработку треугольника

#include "FigTriangle.h"
#include "../../pplib/CreateRegMarkMethod.h"
#include "../../pplib/RegisterSpecialization.h"
#include "../../pplib/RegisterMethod.h"


CREATE_REG_MARK_METHOD(FigTriangle);
REGISTER_SPECIALIZATION(FigTriangle, GetSpecNumAndIncrement, nullptr);

//------------------------------------------------------------------------------
//  Функции используемые для обработки треугольника как специализации фигуры


// Инициализация существующей фигуры-треугольника
void Init(FigTriangle& ft, int a, int b, int c) {
    ft.mark = GetRegMarkFigTriangle();
    Triangle& t = ft._spec;
    Init(t, a, b, c);
}

// Создание фигуры-треугольника без инициализации сторон
FigTriangle* CreateFigTriangle() {
    FigTriangle* pft = new FigTriangle;
    Init(*pft, 0, 0, 0);
    return pft;
}

// Создание фигуры-треугольника с инициализаций сторон
FigTriangle* CreateFigTriangleAndInit(int a, int b, int c) {
    FigTriangle* pft = CreateFigTriangle();
    Init(*pft, a, b, c);
    return pft;
}

// Создание фигуры-треугольника как обобщенной фигуры по совпадению маркера из файла
Figure* CreateFigTriangleUseFileMark(int fileMark) {
    if(fileMark == 2) {
        // Создается треугольник-специализация
        FigTriangle* pft = CreateFigTriangle();
        return  pft;
    }
    return 0;
}

//#include <fstream> - присутствуют в подключаемых файлах
//using namespace std;

// Ввод специализации фигуры-треугольника из потока
void In(ifstream &ifst, FigTriangle& ft) {
    Triangle& t = ft._spec;
    In(ifst, t);
}

// Вывод специализации фигуры-треугольника в поток
void Out(ofstream &ofst, FigTriangle& ft) {
    ofst << "Triangle is as Specialization of Figure: a = " << ft._spec.a 
         << ", b = " << ft._spec.b << ", c = " << ft._spec.c << endl;
}

// Функции - оболочки, используемые для параметризации данной специализации
#include <iostream>

// Ввод специализации фигуры-треугольника из потока как фигуры
void InFigTriangleValue(ifstream &ifst, Figure& f) {
    // Проверка на всякий случай
    if(f.mark == GetRegMarkFigTriangle()) {
        In(ifst, static_cast<FigTriangle&>(f));
    }
    else {
        cerr << "InFigTriangle: Incorrect convertion Figure to FigTriangle" << endl;
        throw; // Exeption;
    }
}

// Вывод специализации фигуры-треугольника в поток как фигуры
void OutFigTriangle(ofstream &ofst, Figure& f) {
    // Проверка на всякий случай
    if(f.mark == GetRegMarkFigTriangle()) {
        Out(ofst, static_cast<FigTriangle&>(f));
    }
    else {
        cerr << "OutFigTriangle: Incorrect convertion Figure to FigTriangle" << endl;
        throw; // Exeption;
    }
}




// Организация регистрации функций, обеспечивающих процедурно-параметрический полиморфизм

REGISTER_METHOD(createFigureUseFileMark, CreateFigTriangleUseFileMark, GetRegMarkFigTriangle(), nullptr);

REGISTER_METHOD(inFigureValue, InFigTriangleValue, GetRegMarkFigTriangle(), nullptr);

REGISTER_METHOD(outFigure, OutFigTriangle, GetRegMarkFigTriangle(), nullptr);


/*
// Организация регистрации функций, обеспечивающих процедурно-параметрический полиморфизм
namespace {
    // Класс, обеспечивающий формирование нужных связей в своем конструкторе.
    class Register {
    public:
        Register(const char* regInfo);
    };

    Register::Register(const char* regInfo) {
        cout << regInfo << endl;
        figuresCounter++;
        cout << "FigTriangle was registered using number " << figuresCounter << endl;

        // Регистрация функции создания фигуры по маркеру файла
        createFigureUseFileMark[triangleMark] = CreateFigTriangleUseFileMark;
        cout << "    createFigureUseFileMark[" << triangleMark << "] = CreateFigTriangleUseFileMark" << endl;
        
	// Регистрация функции ввода значений треугольника-специализации
        inFigureValue[triangleMark] = InFigTriangleValue;
        //inFigureValueCounter++;
        cout << "    inFigureValue[" << triangleMark << "] = InFigTriangleValue" << endl;

        // Регистрация функции вывода параметров треугольника-специализации
        outFigure[triangleMark] = OutFigTriangle;
        //outFigureCounter++;
        cout << "    outFigure[" << triangleMark << "] = OutFigTriangle" << endl;
    }

    // Объект, обеспечивающий регистрацию необходимых обработчиков специализаций
    Register trianRegister("Registration of: CreateFigTriangleUseFileMark, InFigTriangleValue, OutFigTriangle");
}*/
