UML Sınıf Diyagramları (Önce / Sonra)
1. Önce (Faz 0 - İlk Durum)
`main.cpp` oyun döngüsü, tüm somut figür sınıflarına doğrudan bağımlıydı ve tight coupling mevcuttu.

```mermaid
classDiagram
    class Main {
        +main()
        +randomShapes()
    }
    class Lshape {
        +initializeShapeMatrix()
    }
    class Ishape {
        +initializeShapeMatrix()
    }
    class Tshape {
        +initializeShapeMatrix()
    }
    class Jshape {
        +initializeShapeMatrix()
    }

    Main ..> Lshape : Doğrudan Bağımlı (New)
    Main ..> Ishape : Doğrudan Bağımlı (New)
    Main ..> Tshape : Doğrudan Bağımlı (New)
    Main ..> Jshape : Doğrudan Bağımlı (New)
2. Sonra (Faz 1 - Factory Method Sonrası)
Factory Method uygulandıktan sonra main.cpp somut sınıflardan tamamen izole edildi ve gevşek bağımlılık (loose coupling) sağlandı.
classDiagram
    class Main {
        +main()
    }
    class Factory {
        +randomShapes() std::unique_ptr~Shape~
    }
    class Shape {
        <<abstract>>
        +input()
        +moveDown()
    }
    class Lshape {
        +initializeShapeMatrix()
    }
    class Ishape {
        +initializeShapeMatrix()
    }
    class Tshape {
        +initializeShapeMatrix()
    }

    Main ..> Factory : Nesne Talep Eder
    Factory ..> Shape : Üretir (std::unique_ptr)
    Lshape --|> Shape : Miras Alır (Inherits)
    Ishape --|> Shape : Miras Alır (Inherits)
    Tshape --|> Shape : Miras Alır (Inherits)
    Main ..> Shape : Sadece Arayüzü Kullanır
