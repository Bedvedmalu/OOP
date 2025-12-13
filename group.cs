using System.Xml.Serialization;
using System.IO;
using System.Runtime.CompilerServices;

[XmlRoot("Group")]
[XmlInclude(typeof(GroupLeader))]
public class Group
{
    [XmlArray("Students")]
    [XmlArrayItem(typeof(Student), ElementName = "Student")]
    [XmlArrayItem(typeof(GroupLeader), ElementName = "GroupLeader")]

    public List<Student> students { get; set; }

    public string groupname { get; set; }

    public int next_id { get; set; }



    public Group()
    {
        students = new List<Student>();
        next_id = 1;
        groupname = "";
    }

    public void addStudent()
    {
        Student newStudent = new Student();
        newStudent.readFromConsole();
        newStudent.student_id = next_id;
        students.Add(newStudent);
        next_id++;
    }

    public void addGroupLeader()
    {
        GroupLeader newGroupLeader = new GroupLeader();
        newGroupLeader.student_id = next_id;
        newGroupLeader.readFromConsole();
        students.Add(newGroupLeader);
        next_id++;
    }

    public void showAll()
    {
        if (students.Count == 0)
        {
            Console.WriteLine("Список студентов пуст");
            return;
        }

        for (int i = 0; i < students.Count; i++)
        {
            Console.WriteLine("----------------------------------");
            students[i].writeToConsole();
            Console.WriteLine("----------------------------------");
        }
    }

    public void deleteAllStudents()
    {
        students.Clear();
        Console.WriteLine("Студенты удалены");
    }

    public void serialize(string inFile)
    {
        XmlSerializer serializer = new XmlSerializer(typeof(Group));

        using (FileStream file = new FileStream(inFile, FileMode.Create))
        {
            serializer.Serialize(file, this);
        }
        Console.WriteLine("Сохранено");
    }

    public void deserialize(string outFile)
    {
        if (File.Exists(outFile))
        {
            XmlSerializer serializer = new XmlSerializer(typeof(Group));

            using (FileStream file = new FileStream(outFile, FileMode.Open))
            {
                Group readedGroup = (Group)serializer.Deserialize(file);
                this.students = readedGroup.students;
                this.next_id = readedGroup.next_id;
                this.groupname = readedGroup.groupname;
            }
            Console.WriteLine("Загружено");
        }
        else
        {
            Console.WriteLine("Нет такого файла: " + outFile);
        }
        
    }
}