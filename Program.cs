class Program
{
    static public void ShowMenu()
    {
        Console.WriteLine("1. Добавить студента");
        Console.WriteLine("2. Добавить старосту");
        Console.WriteLine("3. Показать всех студентов");
        Console.WriteLine("4. Сохранить");
        Console.WriteLine("5. Загрузить");
        Console.WriteLine("6. Удалить вех студентов");
        Console.WriteLine("7. Выход");
    }

    static public int intInput(int minValue, int maxValue)
    {
        Console.WriteLine("Выберите действие: ");
        string input;
        int value;
        while (true)
        {
            input = Console.ReadLine();

            if (!int.TryParse(input, out value) || ((value < minValue) && (value > maxValue)))
            {
                Console.WriteLine("Неправильный вводю Попробуйте еще раз");
            }
            else
            {
                return value;
            }
        }
    }

    static void Main(string[] args)
    {
        Group group = new Group();
        int choice;
        do
        {
            Program.ShowMenu();
            choice = Program.intInput(0, 7);
            switch (choice)
            {
                case 1:
                    {
                        group.addStudent();
                        break;
                    }
                case 2:
                    {
                        group.addGroupLeader();
                        break;
                    }
                case 3:
                    {
                        group.showAll();
                        break;
                    }
                case 4:
                    {
                        Console.WriteLine("Введите имя файла:");
                        string filename = Console.ReadLine();
                        group.serialize(filename);
                        break;
                    }
                case 5:
                {
                        Console.WriteLine("Введите имя файла:");
                        string filename = Console.ReadLine();
                        group.deserialize(filename);
                        break;
                }
                case 6:
                {
                        group.deleteAllStudents();
                        break;
                }
                default:
                    {
                        Console.WriteLine("Неправильный ввод");
                        break;
                    }
            }
        } while (choice != 7);

    }
}