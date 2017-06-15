// FigCircle.cpp - Реализация функций, осуществляющих обработку круга

#include <iostream>
#include "FigCircle.h"

#include "../../pplib/CreateRegMarkMethod.h"
#include "../../pplib/RegisterSpecialization.h"
#include "../../pplib/RegisterMethod.h"
#include "../../pplib/CreateBaseMethods.h"
#include "../../pplib/CreateBaseMethodsProt.h"



CREATE_REG_MARK_METHOD(FigCircle);
REGISTER_SPECIALIZATION(Figure, FigCircle, "Registration of: FigCircle");

INIT_v2(FigCircle);
//INIT(FigCircle, r);
CREATE(FigCircle);
//CREATEANDINIT_v2(FigCircle, Circle);
//CREATEANDINIT(FigCircle, Circle, r);



IN(FigCircle, Circle);
OUT(FigCircle, Circle);

DELETE(FigCircle);

//------------------------------------------------------------------------------
//  Функции используемые для обработки круга как специализации фигуры
/*
// Инициализация существующей фигуры-круга
void Init(FigCircle& fc, int r) {
    fc.mark = GetRegMarkFigCircle();
    Circle& c = fc._spec;
    Init(c, r);
}

// Создание фигуры-круга без инициализации сторон
FigCircle* CreateFigCircle() {
    FigCircle* pfc = new FigCircle;
    Init(*pfc, 0);
    return pfc;
}

// Создание фигуры-круга с инициализаций сторон
FigCircle* CreateFigCircleAndInit(int r) {
    FigCircle* pfc = CreateFigCircle();
    Init(*pfc, r);
    return pfc;
}

// Ввод специализации фигуры-круга из потока
void In(FigCircle& fc, ifstream &ifst) {
    Circle& c = fc._spec;
    In(ifst, c);
}

// Вывод специализации фигуры-круга в поток
void Out(FigCircle& fc, ofstream &ofst) {
    ofst << "Circle is as Specialization of Figure: r = " << fc._spec.r << endl;
}

// Удаление специализации фигуры-круга
void DeleteFigCircle(FigCircle& pfc) {
    delete &pfc;
}
*/

//=============================================================================
// Функции - оболочки, используемые для параметризации данной специализации,
// Регистрируемые в соответствующих параметрических массивах
//=============================================================================

REGISTER_METHOD_WITH_CHECK_RET_PTR(CreateFigureUseFileMark, CreateFigCircle, FigCircle, "Registration of CreateFigCircleUseFileMark", 3, Figure);
REGISTER_METHOD_WITH_CHECK(InFigureValue, In, "Registration of InFigCircleValue", FigCircle, ifstream&);
REGISTER_METHOD_WITH_CHECK(OutFigure, Out, "Registration of OutFigCircle", FigCircle, ofstream&);
REGISTER_METHOD_WITH_CHECK(DeleteFigure, DeleteFigCircle, "Registration of DeleteFigCircleSkin", FigCircle);

