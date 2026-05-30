#include <raylib.h>

int main () {

	InitWindow(400, 400, "Pong");
	SetTargetFPS(60);
	
	// Переменные для ракеток

	int rly = 200;
	int r_speed = 2;
	int rpy = 150;
	
	// Пременные для мяча
	
	int ballX = 200;
	int ballY = 200;
	int ballSpeedX = 1;
	int ballSpeedY = 1;
	int ballSize = 8; 
	
	int point_l = 0; // Счёт для левого игрока
	int point_r = 0; // Счёт для правого игрока

	while (!WindowShouldClose()) {
		
		// Движение левой ракетки

		if (IsKeyDown(KEY_W)) rly -= r_speed;  
		if (IsKeyDown(KEY_S)) rly += r_speed;
		
		// Ограничения что бы ракетка не выходила за границы экрана

		if (rly < 0) rly = 0;
		if (rly > 300) rly = 300;
		
		// Движение правой ракетки
		
		if (IsKeyDown(KEY_UP)) rpy -= r_speed;
		if (IsKeyDown(KEY_DOWN)) rpy += r_speed;
		
		if (rpy < 0) rpy = 0;
		if (rpy > 300) rpy = 300;
		
		// Движение мяча
		
		ballX += ballSpeedX;
		ballY -= ballSpeedY;

		if (ballX < 0) {
			
			point_r++;
			ballX = 200;
			ballY = 200;
			ballSpeedX = 1;
			ballSpeedY = 1;

		}
		if (ballX > 400 - ballSize) {
			
			point_l++;
			ballX = 200;
			ballY =200;
			ballSpeedX = -1;
			ballSpeedY = 1;

		}

		if (ballY < 0) {
		
			ballY = 0;
			ballSpeedY = -ballSpeedY;

		}

		if (ballY > 400) {
		
			ballY = 400 - ballSize;
			ballSpeedY = -ballSpeedY;
		
		}

		// Столкновение с левой ракеткой

		if (ballX <= 60 && ballX + ballSize >= 50 && ballY +ballSize >= rly && ballY <= rly + 100) {
		
			ballSpeedX = -ballSpeedX;
			ballX = 60;

		}
			
		// Столкновение с правой ракеткой
		
		if (ballX + ballSize >= 340 && ballX <= 350 && ballY + ballSize >= rpy && ballY <= rpy + 100) {
		
			ballSpeedX = -ballSpeedX;
			ballX = 340 - ballSize;

		}

		BeginDrawing(); // Окно
		ClearBackground(BLACK); // Цвет окна
		DrawRectangle(50, rly, 10, 100, WHITE); // Левая ракетка
		DrawRectangle(340, rpy, 10, 100, WHITE); // Правая ракетка
		DrawRectangle(ballX, ballY, ballSize, ballSize, WHITE); // Мяч

		// Счёт 
		DrawText(TextFormat("%d", point_l), 150, 20, 40, WHITE);
		DrawText(TextFormat("%d", point_r), 230, 20, 40, WHITE);
		EndDrawing();

	}

	CloseWindow();
	return 0;
	
		
}
