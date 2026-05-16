State pattern, projemizde "if-else" ve "switch-case" kod kalabalığını çözüyor.
Eski kodlarda oyunun durumunu (oyun anı veya oyun bitti ekranı) kontrol etmek için çok fazla if-else kullanıyorduk. Bu yüzden kodlar çok karışık oluyordu.
Şimdi State pattern ile her durumu (GameplayState ve GameOverState) ayrı bir sınıf yaptık. GameEngine sadece aktif duruma işi devrediyor (delegation). Bu sayede kodlarımız çok daha temiz oldu ve ileride yeni bir durum (mesela Pause ekranı) eklemek çok kolaylaştı.
