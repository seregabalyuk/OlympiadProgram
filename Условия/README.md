# Начало

<details>
<summary> Главы </summary>

- [Начало](#начало)
- [Тело](#тело)
- [Тело](#тело)
- [Условие](#условия)
- [Если не](#если-не)


</details>

# Тело
В с++ важную роль играют фигурные скобки `{` `}`.

Скобки вместе со всеми внутреними командами образуют **тело**. Пример:

```c++
{ // начало тела
    ... // комманды
} // конец тела
```

Внутри каждого **тела** своё **пространство имён**.
Это значит, что в разных телах можно называть переменную одинаково.
Пример:

```c++
int main {
    {
        int a; // одна перемменая 
    }
    {
        int a; // уже другая, они не связаны
    }
}
```
> **Замечание:** из переменную из одного тела нельзя обрабатывать в другом.
>
> На самом деле сама переменная имеет срок жизни, и когда тело заканчивается она умерает.
> Пример:
>```c++
>#include <iostream>
>
>int main {
>    {
>        int a; // одна перемменая 
>    }
>    std::cout << a; // будет ошибка
>                    // так как переменной a уже не существует
>}
>```

Так же вы могли уже заметить, одно **тело** может существовать в другом.
И **внутренее тело** имеет **достук** к переменным **внешнего тела**, а внешнее не имеет доступ к внутренему. 
Пример: 
```c++
#include <iostream>

int a = 1;

int main() {
    int a = 10;
    {
        std::cout << a; // Выведет 10
    }
    {
        int a = 100;
        std::cout << a; // Выведет 100
        // так как более внутренняя переменная имеет больший приоритет
        std::cout << ::a; // Выведет 1
        // так мы можем обратиться к внешнему телу
        // но здесь есть ньюансы
    }
}
```
# Условия

Условия в с++ задаются с помощью слова **`if`**.
Имеет такой синтаксис:

```c++
if (/*Условие, то есть выражение которое возращает bool*/) 
{ // начало тело

    ... // код, который выполняется если условие = true

} // конец тела
```

Пример:

```c++
#include <iostream>

using namespace std;

int main() {
    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 130) { // вспоминаем операторы
        cout << "You have unreal age! Cool!\n";
    }
}
```

Ещё можно скобки не писать, тогда телом условия будет следущая команда после. Пример:

```c++
#include <iostream>

using namespace std;

int main() {
    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 130)
        cout << "You have unreal age! Cool!\n";
}
```

# Если не

Так же нам хочется, чтобы пре не выполнении условия выполнялся другой код.
С этим нам поможет слово **`else`**. 
Имеет такой синтаксис:

```c++
if (/*Условие, то есть выражение которое возращает bool*/) 
{ // начало тело

    ... // код, который выполняется если условие = true

} else { // конец тела, начало нового
    
    ... // код, который выполняется если условие = false

} // конец тела
```

Пример:

```c++
#include <iostream>

using namespace std;

int main() {
    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 130) {
        cout << "You have unreal age! Cool!\n";
    } else {
        cout << "Yor age is good.\n";
    }
}
```

Аналогично **`if`**, **`else`** при отсутвии скобок считает телом следущую команду после. Пример:

```c++
#include <iostream>

using namespace std;

int main() {
    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 130) 
        cout << "You have unreal age! Cool!\n";
    else
        cout << "Yor age is good.\n";
}
```

> **Замечание:** `if {} else {}` являются одной командой.

Из замечания следует интересное свойство.
Можно написать несколько поледовательных условий. Пример:

```c++
#include <iostream>

using namespace std;

int main() {
    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 130) {
        cout << "You have unreal age! Cool!\n";
    } else if (age <= 18) {
        cout << "You are child.\n";
    } else if (age <= 60) {
        cout << "You are adult.\n";
    } else {
        cout << "You are old.\n";
    }
}
```

То же самое, но подругому:

```c++
#include <iostream>

using namespace std;

int main() {
    cout << "Enter your age: ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 130)
        cout << "You have unreal age! Cool!\n";
    else if (age <= 18)
        cout << "You are child.\n";
    else if (age <= 60)
        cout << "You are adult.\n";
    else
        cout << "You are old.\n";
}
```

![](https://i.imgur.com/CZHiYO0.png)