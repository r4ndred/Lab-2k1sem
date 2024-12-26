#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовый класс для всех устройств
class Device {
public:
    // Конструктор для инициализации общих свойств устройств
    Device(const string& partNumber, const string& brand, double price)
        : partNumber(partNumber), brand(brand), price(price) {}

    // Чисто виртуальная функция для вывода информации об устройстве
    virtual void displayInfo() const = 0;

    // Виртуальный деструктор для корректного удаления объектов
    virtual ~Device() = default;

    // Метод для вывода краткой информации (только номер и модель)
    void displayShortInfo() const {
        cout << partNumber << ", " << brand << endl;
    }

protected:
    string partNumber; // Номенклатурный номер устройства
    string brand;      // Бренд устройства
    double price;      // Стоимость устройства
};

// Класс для наушников
class Headphones : public Device {
public:
    // Конструктор для инициализации свойств наушников
    Headphones(const string& partNumber, const string& brand, double price,
               const string& designType, const string& mountingType)
        : Device(partNumber, brand, price), designType(designType), mountingType(mountingType) {}

    // Реализация метода для вывода информации о наушниках (в виде списка)
    void displayInfo() const override {
        cout << "Наушники:" << endl;
        cout << "  Номенклатурный номер: " << partNumber << endl;
        cout << "  Бренд: " << brand << endl;
        cout << "  Цена: $" << price << endl;
        cout << "  Тип конструкции: " << designType << endl;
        cout << "  Способ крепления: " << mountingType << endl;
    }

private:
    string designType;  // Тип конструкции наушников
    string mountingType; // Способ крепления наушников
};

// Класс для микрофонов
class Microphone : public Device {
public:
    // Конструктор для инициализации свойств микрофонов
    Microphone(const string& partNumber, const string& brand, double price,
               const string& frequencyRange, double sensitivity)
        : Device(partNumber, brand, price), frequencyRange(frequencyRange), sensitivity(sensitivity) {}

    // Реализация метода для вывода информации о микрофонах (в виде списка)
    void displayInfo() const override {
        cout << "Микрофон:" << endl;
        cout << "  Номенклатурный номер: " << partNumber << endl;
        cout << "  Бренд: " << brand << endl;
        cout << "  Цена: $" << price << endl;
        cout << "  Частотный диапазон: " << frequencyRange << endl;
        cout << "  Чувствительность: " << sensitivity << " дБ" << endl;
    }

private:
    string frequencyRange; // Частотный диапазон микрофона
    double sensitivity;    // Чувствительность микрофона
};

// Класс для клавиатур
class Keyboard : public Device {
public:
    // Конструктор для инициализации свойств клавиатур
    Keyboard(const string& partNumber, const string& brand, double price,
             const string& switchType, const string& interfaceType)
        : Device(partNumber, brand, price), switchType(switchType), interfaceType(interfaceType) {}

    // Реализация метода для вывода информации о клавиатурах (в виде списка)
    void displayInfo() const override {
        cout << "Клавиатура:" << endl;
        cout << "  Номенклатурный номер: " << partNumber << endl;
        cout << "  Бренд: " << brand << endl;
        cout << "  Цена: $" << price << endl;
        cout << "  Тип переключателей: " << switchType << endl;
        cout << "  Интерфейс: " << interfaceType << endl;
    }

private:
    string switchType;    // Тип переключателей клавиатуры
    string interfaceType; // Интерфейс подключения клавиатуры
};

// Функция для вывода пронумерованного списка устройств (только номера и модели)
void displayNumberedList(const vector<Device*>& devices) {
    cout << "Список устройств:" << endl;
    for (size_t i = 0; i < devices.size(); ++i) {
        cout << i + 1 << ". ";
        devices[i]->displayShortInfo();
    }
    cout << devices.size() + 1 << ". Вернуться в меню" << endl; // Добавляем пункт "Вернуться в меню"
}

// Функция для вывода информации о выбранном устройстве и предложения действий
void displaySelectedDevice(const vector<Device*>& devices, int index) {
    if (index >= 1 && index <= devices.size()) {
        cout << "\nИнформация о выбранном устройстве:" << endl;
        devices[index - 1]->displayInfo();

        // Предлагаем пользователю выбор: вернуться в меню или выйти
        int action;
        cout << "\nВыберите действие:" << endl;
        cout << "1. Вернуться в меню" << endl;
        cout << "2. Выход" << endl;
        cout << "Введите номер действия: ";
        cin >> action;

        if (action == 2) { // Если выбран выход
            cout << "Завершение программы." << endl;
            exit(0); // Завершаем программу
        }
        // Если выбран возврат в меню, просто выходим из функции
    } else {
        cout << "Неверный номер. Пожалуйста, выберите номер из списка." << endl;
    }
}

// Меню для выбора категории устройств
void categoryMenu(const vector<Device*>& headphones, const vector<Device*>& microphones, const vector<Device*>& keyboards) {
    while (true) {
        cout << "\nВыберите категорию устройств:" << endl;
        cout << "1. Наушники" << endl;
        cout << "2. Микрофоны" << endl;
        cout << "3. Клавиатуры" << endl;
        cout << "4. Выход" << endl;

        int choice;
        cout << "Введите номер категории: ";
        cin >> choice;

        if (choice == 1) { // Наушники
            while (true) {
                displayNumberedList(headphones);
                int deviceChoice;
                cout << "\nВведите номер наушников для получения информации или выберите вернуться в меню: ";
                cin >> deviceChoice;

                if (deviceChoice == headphones.size() + 1) { // Вернуться в меню
                    break;
                } else if (deviceChoice >= 1 && deviceChoice <= headphones.size()) { // Выбрано устройство
                    displaySelectedDevice(headphones, deviceChoice);
                } else {
                    cout << "Неверный номер. Пожалуйста, выберите номер из списка." << endl;
                }
            }
        } else if (choice == 2) { // Микрофоны
            while (true) {
                displayNumberedList(microphones);
                int deviceChoice;
                cout << "\nВведите номер микрофона для получения информации или выберите вернуться в меню: ";
                cin >> deviceChoice;

                if (deviceChoice == microphones.size() + 1) { // Вернуться в меню
                    break;
                } else if (deviceChoice >= 1 && deviceChoice <= microphones.size()) { // Выбрано устройство
                    displaySelectedDevice(microphones, deviceChoice);
                } else {
                    cout << "Неверный номер. Пожалуйста, выберите номер из списка." << endl;
                }
            }
        } else if (choice == 3) { // Клавиатуры
            while (true) {
                displayNumberedList(keyboards);
                int deviceChoice;
                cout << "\nВведите номер клавиатуры для получения информации или выберите вернуться в меню: ";
                cin >> deviceChoice;

                if (deviceChoice == keyboards.size() + 1) { // Вернуться в меню
                    break;
                } else if (deviceChoice >= 1 && deviceChoice <= keyboards.size()) { // Выбрано устройство
                    displaySelectedDevice(keyboards, deviceChoice);
                } else {
                    cout << "Неверный номер. Пожалуйста, выберите номер из списка." << endl;
                }
            }
        } else if (choice == 4) { // Выход
            cout << "Завершение программы." << endl;
            break;
        } else {
            cout << "Неверный номер. Пожалуйста, выберите номер из списка." << endl;
        }
    }
}

int main() {
    // Создаем списки устройств: 3 наушника, 3 микрофона, 3 клавиатуры
    vector<Device*> headphones = {
        new Headphones("H123", "Logitech G435", 99.99, "Накладные", "Оголовье"),
        new Headphones("H456", "Razer Kraken Pro", 79.99, "Накладные", "Оголовье"),
        new Headphones("H789", "HyperX Cloud II", 149.99, "Накладные", "Оголовье")
    };

    vector<Device*> microphones = {
        new Microphone("M123", "Blue Yeti", 129.99, "20Гц-20кГц", 120),
        new Microphone("M456", "Razer Seiren", 149.99, "30Гц-20кГц", 118),
        new Microphone("M789", "Audio-Technica AT2020", 99.99, "20Гц-20кГц", 114)
    };

    vector<Device*> keyboards = {
        new Keyboard("K123", "Logitech G Pro", 129.99, "Механические", "USB"),
        new Keyboard("K456", "Razer BlackWidow", 159.99, "Оптические", "USB"),
        new Keyboard("K789", "Corsair K95", 199.99, "Механические", "USB")
    };

    // Запускаем меню выбора категории
    categoryMenu(headphones, microphones, keyboards);

    // Освобождаем память
    for (auto device : headphones) delete device;
    for (auto device : microphones) delete device;
    for (auto device : keyboards) delete device;

    return 0;
}