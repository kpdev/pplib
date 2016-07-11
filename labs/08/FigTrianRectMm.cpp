// FigTrianRectMm.cpp - Реализация обработчиков специализаций мультиметода
// для всех комбинаций треугольника и прямоугольника
// сделано в одном файле, но может быть и разнесено

#include "FigTriangle.h"
#include "FigRectangle.h"
#include "FigMm.h"
#include <iostream>

#include "../../pplib/CreateMMSpec.h"

//------------------------------------------------------------------------------
// Функции-обработчики специализаций

//  Обработчик специализации, вычисляющий отношения между двумя треугольниками
void TrianTrianOut(FigTriangle& ft1, FigTriangle& ft2, ofstream &ofst) {
    ofst << "This is two Triangles" << endl;
    ofst << "     ";
    Out(ofst, ft1);
    ofst << "     ";
    Out(ofst, ft2);
}

//  Обработчик специализации, вычисляющий отношения между треугольником и прямоугольником
void TrianRectOut(FigTriangle& ft1, FigRectangle& fr2, ofstream &ofst) {
    ofst << "We have Triangle and Rectangle" << endl;
    ofst << "     ";
    Out(ofst, ft1);
    ofst << "     ";
    Out(ofst, fr2);
}

//  Обработчик специализации, вычисляющий отношения между прямоугольником и треугольником
void RectTrianOut(FigRectangle& fr1, FigTriangle& ft2, ofstream &ofst) {
    ofst << "The first figure is Rectangle and second is Triangle" << endl;
    ofst << "     ";
    Out(ofst, fr1);
    ofst << "     ";
    Out(ofst, ft2);
}

//  Обработчик специализации, вычисляющий отношения между двумя прямоугольниками
void RectRectOut(FigRectangle& fr1, FigRectangle& fr2, ofstream &ofst) {
    ofst << "Rectangle + Rectangle = Two Rectangles" << endl;
    ofst << "     ";
    Out(ofst, fr1);
    ofst << "     ";
    Out(ofst, fr2);
}

//------------------------------------------------------------------------------
// Функции-оболочки над обработчикаи специализаций
/*
// Оболочка вокруг обработчика двух треугольников
void MmTrianTrianSpecOut(Figure& f1, Figure& f2, ofstream& ofst) {
    // Проверка на всякий случай
    if(f1.mark == GetRegMarkFigTriangle() && f2.mark == GetRegMarkFigTriangle()) {
        return TrianTrianOut(static_cast<FigTriangle&>(f1), static_cast<FigTriangle&>(f2), ofst);
    }
    else {
        cerr << "MmTrianTrianSpecOut: Incorrect convertion one of Figures" << endl;
        throw; // Exeption;
    }
}
*/

CREATE_MM_SPEC(MmTrianTrianSpecOut, Figure, FigTriangle, FigTriangle, GetRegMarkFigTriangle, GetRegMarkFigTriangle, TrianTrianOut);

/*
// Оболочка вокруг обработчика треугольника с прямоугольником
void MmTrianRectSpecOut(Figure& f1, Figure& f2, ofstream &ofst) {
    // Проверка на всякий случай
    if(f1.mark == GetRegMarkFigTriangle() && f2.mark == GetRegMarkFigRectangle()) {
        return TrianRectOut(static_cast<FigTriangle&>(f1), static_cast<FigRectangle&>(f2), ofst);
    }
    else {
        cerr << "MmTrianRectSpecOut: Incorrect convertion one of Figures" << endl;
        throw; // Exeption;
    }
}
*/

CREATE_MM_SPEC(MmTrianRectSpecOut, Figure, FigTriangle, FigRectangle, GetRegMarkFigTriangle, GetRegMarkFigRectangle, TrianRectOut);

/*
// Оболочка вокруг обработчика прямоугольника с треугольником
void MmRectTrianSpecOut(Figure& f1, Figure& f2, ofstream &ofst) {
    // Проверка на всякий случай
    if(f1.mark == GetRegMarkFigRectangle() && f2.mark == GetRegMarkFigTriangle()) {
        return RectTrianOut(static_cast<FigRectangle&>(f1), static_cast<FigTriangle&>(f2), ofst);
    }
    else {
        cerr << "MmRectTrianSpecOut: Incorrect convertion one of Figures" << endl;
        throw; // Exeption;
    }
}
*/


CREATE_MM_SPEC(MmRectTrianSpecOut, Figure, FigRectangle, FigTriangle, GetRegMarkFigRectangle, GetRegMarkFigTriangle, RectTrianOut);


/*
// Оболочка вокруг обработчика двух прямоугольников
void MmRectRectSpecOut(Figure& f1, Figure& f2, ofstream &ofst) {
    // Проверка на всякий случай
    if(f1.mark == GetRegMarkFigRectangle() && f2.mark == GetRegMarkFigRectangle()) {
        return RectRectOut(static_cast<FigRectangle&>(f1), static_cast<FigRectangle&>(f2), ofst);
    }
    else {
        cerr << "MmRectRectSpecOut: Incorrect convertion one of Figures" << endl;
        throw; // Exeption;
    }
}
*/

CREATE_MM_SPEC(MmRectRectSpecOut, Figure, FigRectangle, FigRectangle, GetRegMarkFigRectangle, GetRegMarkFigRectangle, RectRectOut);

/*
//------------------------------------------------------------------------------
// Организация регистрации функции вычисления периметра, 
// обеспечивающей процедурно-параметрический полиморфизм
namespace {
    // Класс, обеспечивающий формирование нужных связей в своем конструкторе.
    class Register {
    public:
        Register(const char* regInfo);
    };

    Register::Register(const char* regInfo) {
        cout << regInfo << endl;
        // Регистрация функций, используемых в мультиметоде
        MultimethodFuncMMArray[GetRegMarkFigTriangle()][GetRegMarkFigTriangle()] = MmTrianTrianSpecOut;
        cout << "    multimethodFunc[" << GetRegMarkFigTriangle() << "][" << GetRegMarkFigTriangle() << "] = MmTrianTrianSpecOut" << endl;


        MultimethodFuncMMArray[GetRegMarkFigTriangle()][GetRegMarkFigRectangle()] = MmTrianRectSpecOut;
        cout << "    multimethodFunc[" << GetRegMarkFigTriangle() << "][" << GetRegMarkFigRectangle() << "] = MmTrianRectSpecOut" << endl;
        MultimethodFuncMMArray[GetRegMarkFigRectangle()][GetRegMarkFigTriangle()] = MmRectTrianSpecOut;
        cout << "    multimethodFunc[" << GetRegMarkFigRectangle() << "][" << GetRegMarkFigTriangle() << "] = MmRectTrianSpecOut" << endl;
        MultimethodFuncMMArray[GetRegMarkFigRectangle()][GetRegMarkFigRectangle()] = MmRectRectSpecOut;
        cout << "    multimethodFunc[" << GetRegMarkFigRectangle() << "][" << GetRegMarkFigRectangle() << "] = MmRectRectSpecOut" << endl;

    }

    // Объект, обеспечивающий регистрацию необходимых обработчиков специализаций
    Register trianRegisterPerimeter("Registration of: Different combination of Triangle and Rectangle in  Multimethod");
}
*/

BEGIN_REG_MM(MultimethodFuncMMArray);

REG_MM_SPEC(MmTrianTrianSpecOut, GetRegMarkFigTriangle, GetRegMarkFigTriangle);
REG_MM_SPEC(MmTrianRectSpecOut, GetRegMarkFigTriangle, GetRegMarkFigRectangle);
REG_MM_SPEC(MmRectTrianSpecOut, GetRegMarkFigRectangle, GetRegMarkFigTriangle);
REG_MM_SPEC(MmRectRectSpecOut, GetRegMarkFigRectangle, GetRegMarkFigRectangle);

END_REG_MM("Registration of: Different combination of Triangle and Rectangle in  Multimethod");














