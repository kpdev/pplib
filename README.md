PPLIB - библиотека эмуляции ППП подхода в С++ без изменения компилятора и компоновщика. Библиотека состоит из набора макросов и шаблонных структур данных, реализующие табличный доступ к обработчикам специализаций. 

Основные макросы библиотеки:
- CREATE_GENERALIZATION – создание обобщения, в структуру неявно добавляется поле mark, отвечающее за идентификацию типа во время выполнения программы
- CREATE_SPECIALIZATION – создание специализации на основе предварительно созданного обобщения и объявление инициализатора поля mark
- DEFINE_GENERALIZATION_METHOD – определение инициализатора поля mark для созданной специализации
- DECLARE_MM — объявление мультиметода
- DEFINE_MM — определение мультиметода, создание массива обработчиков
- CREATE_MM_SPEC — объявление обработчика специализации
- REG_MM_SPEC — определение обработчика специализации, его запись в массив, выделенный макросом  DEFINE_MM. Макрос  REG_MM_SPEC должен быть использован в блоке между макросами BEGIN_REG_MM и END_REG_MM. Уточнение — в этом блоке может быть более одного макроса  REG_MM_SPEC.

Пример использования библиотеки: 

```cpp
// Создание обобщения
CREATE_GENERALIZATION(Figure);
DEFINE_GENERALIZATION_METHOD(Figure);

// Основы специализаций
struct Triangle { … }; 
struct Rectangle { … }; 

// Создание специализации с именем типа FigTriangle
CREATE_SPECIALIZATION(FigTriangle, Figure, Triangle);
CREATE_REG_MARK_METHOD(FigTriangle);
REGISTER_SPECIALIZATION(Figure, FigTriangle, "Registration of: FigTriangle");

// Создание специализации с именем типа FigRectangle
CREATE_SPECIALIZATION(FigRectangle, Figure, Rectangle);
CREATE_REG_MARK_METHOD(FigRectangle);
REGISTER_SPECIALIZATION(Figure, FigRectangle, "Registration of: FigRectangle");

// Объявление мультиметода, принимающего 2 объекта с типом обобщения Figure
DECLARE_MM(MultimethodFunc, 10, Figure, ofstream&)
// Определение вышеописанного мультиметода и выделение памяти под массив обработчиков
DEFINE_MM(MultimethodFunc, 10);

// Описание функции обработки взаимодействия специализаций FigRectangle и FigTriangle
void RectTrianOut(FigRectangle&, FigTriangle&) { … }

// Создание обработчика специализации
CREATE_MM_SPEC(MmRectTrianSpecOut, Figure, FigRectangle, FigTriangle, GetRegMarkFigRectangle, GetRegMarkFigTriangle, RectTrianOut);

// Запись обработчиков специализации
BEGIN_REG_MM(MultimethodFunc);
// Запись содданного выше  MmRectTrianSpecOut
REG_MM_SPEC(MmRectTrianSpecOut, GetRegMarkFigRectangle, GetRegMarkFigTriangle);
// Запись других обработчиков (для примера)
REG_MM_SPEC(MmRectRectSpecOut, GetRegMarkFigRectangle, GetRegMarkFigRectangle);
REG_MM_SPEC(MmTrianTrianSpecOut, GetRegMarkFigTriangle, GetRegMarkFigTriangle);
REG_MM_SPEC(MmTrianRectSpecOut, GetRegMarkFigTriangle, GetRegMarkFigRectangle);
END_REG_MM("Registration of: Different combination of Triangle and Rectangle in  Multimethod");
```

С помощью данной библиотеки реализованы примеры расширения функциональности предварительно написанного кода (включены в репозиторий проекта)
