#include <iostream>
#include <fstream>

using namespace std;
ifstream inputFile;
ofstream outputFile;


int max(int firstNumber, int secondNumber){

    if (firstNumber >= secondNumber) return firstNumber;
    else return secondNumber;
}
//нахождение максимума двух чисел 

int main(){

    inputFile.open("turtle.in"); //открываю файл с данными

    int height, width;  // обьявляю высоту и ширину таблицы
    inputFile >> height >> width; //забираю значения высоты и ширины

    int array[height][width]; //обьявляю массив размером height*width
    for (int i = height-1; i >= 0; i--){ //так как по условию мы начинаем двигаться с клетки [height][weight],
    // где height и weight принимают свои максимальные значения, то мы заполняем массив наоборот
    //height-1, так как i начинается с 0 => самый нижний элемент становится [0][j]
        for (int j = 0; j < width; j++){ //прохожу по каждому элемента вложенного массива
        
            inputFile >> array[i][j];
        }
    }
    //запоолняю двумерным массив даннымии из файла
    inputFile.close(); //закрыл файл из которого я брал данные


    for (int i = 1; i < height; i++){
    
        array[i][0] += array[i - 1][0]; //высчитываем сумму первого столбца записывая ее в array[2][0] - по исходным данным
    }
    for (int j = 1; j < width; j++){
        array[0][j] += array[0][j - 1]; // высчитываю сумму первой строки записывая результат в array[0][2]
    }
    for (int i = 1; i < height; i++){
        for (int j = 1; j < width; j++){
            array[i][j] += max(array[i - 1][j], array[i][j - 1]); // записываю в [i][j] элемент максимальную сумму, которую можно было получить из предыдуших ячеек
        }
    }

    outputFile.open("turtle.out"); //открываю файл для записи
    outputFile << array[height - 1][width - 1]; //вывожу в файл ячейку с верхнего правого края ( максимальную сумму)
    outputFile.close(); //закрываю файл
    return 0;
}
