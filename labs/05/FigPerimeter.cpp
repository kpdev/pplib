// FigPerimeter.cpp - Реализация функции, вычисляющей периметр обобщенной фигуры

#include "FigPerimeter.h"

//------------------------------------------------------------------------------
// Реализации глобальных переменных, обеспечивающих подключение зарегистрировнных функций

/*
// Описание переменной, используемой для регистрации функций вычисления периметра
PerimeterFunc perimeterFunc[10];
*/

static const unsigned specializationMax = 10;
DEFINE_GEN_FUNC(PerimeterFunc, specializationMax);

//------------------------------------------------------------------------------
//  Функции вычисления периметра обобщенной фигуры
double Perimeter(Figure& f) {
    PerimeterFunc func = PerimeterFuncArray[f.mark];
    return func(f);
}


