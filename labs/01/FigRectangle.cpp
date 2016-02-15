// FigRectangle.cpp - Реализация функций, осуществляющих обработку прямоугольника

#include "FigRectangle.h"
#include "../../pplib/CreateRegMarkMethod.h"
#include "../../pplib/RegisterSpecialization.h"
#include "../../pplib/RegisterMethod.h"

CREATE_REG_MARK_METHOD(FigRectangle);
REGISTER_SPECIALIZATION(FigRectangle, GetSpecNumAndIncrement, nullptr);

//------------------------------------------------------------------------------
//  Функции используемые для обработки прямоугольника как специализации фигуры

// Инициализация существующей фигуры-прямоугольника
void Init(FigRectangle& fr, int x, int y) {
    fr.mark = GetRegMarkFigRectangle();
    Rectangle& r = fr._spec;
    Init(r, x, y);
}

// Создание фигуры-прямоугольника без инициализации сторон
FigRectangle* CreateFigRectangle() {
    FigRectangle* pfr = new FigRectangle;
    Init(*pfr, 0, 0);
    return pfr;
}

// Создание фигуры-прямоугольника с инициализаций сторон
FigRectangle* CreateFigRectangleAndInit(int x, int y) {
    FigRectangle* pfr = CreateFigRectangle();
    Init(*pfr, x, y);
}

// Создание фигуры-прямоугольника как обобщенной фигуры по совпадению маркера из файла
Figure* CreateFigRectangleUseFileMark(int fileMark) {
    if(fileMark == 1) {
        // Создается прямоугольник-специализация
        FigRectangle* pfr = CreateFigRectangle();
        return  pfr;
    }
    return 0;
}


//#include <fstream> - присутствуют в подключаемых файлах
//using namespace std;

// Ввод специализации фигуры-прямоугольника из потока
void In(ifstream &ifst, FigRectangle& fr) {
    Rectangle& r = fr._spec;
    In(ifst, r);
}

// Вывод специализации фигуры-прямоугольника в поток
void Out(ofstream &ofst, FigRectangle& fr) {
    ofst << "Rectangle is as Specialization of Figure: x = " << fr._spec.x << ", y = " << fr._spec.y << endl;
}

// Функции - оболочки, используемые для параметризации данной специализации
#include <iostream>

// Ввод специализации фигуры-прямоугольника из потока как фигуры
void InFigRectangleValue(ifstream &ifst, Figure& f) {
    // Проверка на всякий случай
    if(f.mark == GetRegMarkFigRectangle()) {
        In(ifst, static_cast<FigRectangle&>(f));
    }
    else {
        cerr << "InFigRectangle: Incorrect convertion Figure to FigRectangle" << endl;
        throw; // Exeption;
    }
}

// Вывод специализации фигуры-прямоугольника в поток как фигуры
void OutFigRectangle(ofstream &ofst, Figure& f) {
    // Проверка на всякий случай
    if(f.mark == GetRegMarkFigRectangle()) {
        Out(ofst, static_cast<FigRectangle&>(f));
    }
    else {
        cerr << "OutFigRectangle: Incorrect convertion Figure to FigRectangle" << endl;
        throw; // Exeption;
    }
}

// Организация регистрации функций, обеспечивающих процедурно-параметрический полиморфизм
REGISTER_METHOD(createFigureUseFileMark, CreateFigRectangleUseFileMark, GetRegMarkFigRectangle(), nullptr);

REGISTER_METHOD(inFigureValue, InFigRectangleValue, GetRegMarkFigRectangle(), nullptr);

REGISTER_METHOD(outFigure, OutFigRectangle, GetRegMarkFigRectangle(), nullptr);



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
        cout << "FigRectangle was registered using number " << figuresCounter << endl;

        // Регистрация функции создания фигуры по маркеру файла
        createFigureUseFileMark[GetRegMarkFigRectangle()] = CreateFigRectangleUseFileMark;
        cout << "    createFigureUseFileMark[" << GetRegMarkFigRectangle() << "] = CreateFigRectangleUseFileMark" << endl;
        
	// Регистрация функции ввода значений прямоугольника-специализации
        inFigureValue[GetRegMarkFigRectangle()] = InFigRectangleValue;
        //inFigureValueCounter++;
        cout << "    inFigureValue[" << GetRegMarkFigRectangle() << "] = InFigRectangleValue" << endl;

        // Регистрация функции вывода параметров прямоугольника-специализации
        outFigure[GetRegMarkFigRectangle()] = OutFigRectangle;
        // outFigureCounter++;
        cout << "    outFigure[" << GetRegMarkFigRectangle() << "] = OutFigRectangle" << endl;
    }


    // Объект, обеспечивающий регистрацию необходимых обработчиков специализаций
    Register rectanRegister("Registration of: CreateFigRectangleUseFileMark, InFigRectangleValue, OutFigRectangle");
}*/
