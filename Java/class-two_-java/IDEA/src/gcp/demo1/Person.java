package gcp.demo1;

public class Person {
    private String name;
    private int age;

    public Person() {
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

//    @Override
//    public boolean equals(Object obj) {
//        System.out.println("pppp");
//        //return super.equals(obj);
//        if(this == obj) {
//            return true;
//        }
//        if (obj instanceof Person ) {
//            Person o = (Person)obj;
//            if (age == o.age && name.equals(o.name)) {
//                return true;
//            }
//        }
//        return false;
//    }

//    @Override
//    public boolean equals(Object o) {
//        if (this == o) return true;
//        if (o == null || getClass() != o.getClass()) return false;
//        Person person = (Person) o;
//        return age == person.age && Objects.equals(name, person.name);
//    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }




//    @Override
//    public int hashCode() {
//        return super.hashCode();
//    }
}
