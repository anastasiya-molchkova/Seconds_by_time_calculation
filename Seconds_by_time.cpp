/* Напишите функцию int f(int h, int m, int s), которая принимает три целых аргумента (часы h, минуты m и секунды s) 
и возвращает количество секунд, прошедших с начала дня. */

#include <iostream>

// получаем от пользователя натуральное число меньше заданного 
unsigned get_natural_number_less_than(const unsigned& max)
{
	int number;
	std::cin >> number;
	while ((std::cin.fail()) || (number < 0) || (number >= max))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Повторите ввод, нужно ввести число от 0 до " << (max-1) << ": ";
		std::cin >> number;
	}
	std::cin.ignore(1000, '\n');
	return  static_cast<unsigned>(number);
}

// вычисляет прошедшие с начала дня секунды по времени: часам, минутам и секундам
unsigned calculate_seconds_by_time(const unsigned& hours, const unsigned& minutes, const unsigned& seconds)
{
	static const unsigned seconds_in_one_hour = 3600;
	static const unsigned seconds_in_one_minute = 60;
	return ((hours*seconds_in_one_hour)+(minutes*seconds_in_one_minute)+seconds);
}

int main()
{
	setlocale(LC_CTYPE, "rus");  // подключаем кириллицу для вывода сообщений пользователю

	std::cout << "Программа вычисляет количество секунд по заданному времени. Введите время по очереди.\n";
	std::cout << "Введите часы (от 0 до 23): ";
	unsigned hours = get_natural_number_less_than(24);
	std::cout << "Введите минуты (от 0 до 59): ";
	unsigned minutes = get_natural_number_less_than(60);
	std::cout << "Введите секунды (от 0 до 59): ";
	unsigned seconds = get_natural_number_less_than(60);

	std::cout << "Итого секунд: " << calculate_seconds_by_time(hours, minutes, seconds) << std::endl;
	return 0;
}