using System.Xml.Serialization;

[XmlRoot("Student")]
public class Student
{
    [XmlElement("StudentID")]
    public int student_id { get; set; }

    [XmlElement("FirstName")]
    public string firstname { get; set; }

    [XmlElement("SecondName")]
    public string secondname { get; set; }

    [XmlElement("Age")]
    public int age { get; set; }

    [XmlElement("GroupName")]
    public string groupname { get; set; }


    public Student()
    {
        student_id = 0;
        firstname = "";
        secondname = "";
        age = 0;
        groupname = "";
    }

    public Student(int id, string fname, string sname, int stage, string group)
    {
        student_id = id;
        firstname = fname;
        secondname = sname;
        age = stage;
        groupname = group;
    }

    public virtual void writeToConsole()
    {
        Console.WriteLine("ID: " + student_id);
        Console.WriteLine("Имя: " + firstname);
        Console.WriteLine("Фамилия: " + secondname);
        Console.WriteLine("Возраст: " + age);
        Console.WriteLine("Группа: " + groupname);
    }

    public virtual void readFromConsole()
    {
        Console.WriteLine("Имя: ");
        firstname = Console.ReadLine();
        Console.WriteLine("Фамилия: ");
        secondname = Console.ReadLine();
        Console.WriteLine("Возраст: ");
        age = int.Parse(Console.ReadLine());
    }
}
