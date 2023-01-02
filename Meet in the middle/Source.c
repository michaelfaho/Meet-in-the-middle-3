#include<stdio.h>
#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>

int main()
{
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* timer;

	ALLEGRO_BITMAP* board = NULL;
	ALLEGRO_BITMAP* tas = NULL;
	ALLEGRO_BITMAP* menu1 = NULL;
	ALLEGRO_BITMAP* menu2 = NULL;
	ALLEGRO_BITMAP* menu3 = NULL;

	ALLEGRO_BITMAP* matau = NULL;
	ALLEGRO_BITMAP* onewa = NULL;

	ALLEGRO_BITMAP* matoran_matau = NULL;
	ALLEGRO_BITMAP* matoran_onewa = NULL;

	al_init();

	display = al_create_display(1700, 980);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_install_keyboard();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));


	al_init_image_addon();
	board = al_load_bitmap("img/Board.png");
	assert(board != NULL);
	tas = al_load_bitmap("img/Tas.png");
	assert(tas != NULL);
	menu1 = al_load_bitmap("img/Menu1.png");
	assert(tas != NULL);
	menu2 = al_load_bitmap("img/Menu2.png");
	assert(tas != NULL);
	menu3 = al_load_bitmap("img/Menu3.png");
	assert(tas != NULL);

	matau = al_load_bitmap("img/Matau.png");
	assert(matau != NULL);
	onewa = al_load_bitmap("img/Onewa.png");
	assert(onewa != NULL);

	matoran_matau = al_load_bitmap("img/Matoran_Matau.png");
	assert(matoran_matau != NULL);
	matoran_onewa = al_load_bitmap("img/Matoran_Onewa.png");
	assert(matoran_onewa != NULL);


	bool running = true;
	float x = 0, y = -500;
	int width = al_get_display_width(display);//don't need


	al_start_timer(timer);
	while (running) {
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			running = false;

		if (event.type == ALLEGRO_EVENT_TIMER) {
			al_clear_to_color(al_map_rgba_f(150, 150, 150, 105));//background color

			al_draw_bitmap(board, 305, y += 5, 0);
			al_draw_bitmap(tas, 1335, 810, 0);
			al_draw_bitmap(menu1, -130, 10, 0);
			al_draw_bitmap(menu2, -70, 10, 0);
			al_draw_bitmap(menu3, 83, 36, 0);

			al_draw_bitmap(matau, 95, 830, 0);
			al_draw_bitmap(matau, 195, 830, 0);
			al_draw_bitmap(onewa, 1400, 60, 0);
			al_draw_bitmap(onewa, 1500, 60, 0);

			al_draw_bitmap(matoran_matau, 175, 577, 0);
			al_draw_bitmap(matoran_matau, 40, 480, 0);
			al_draw_bitmap(matoran_matau, 175, 385, 0);
			al_draw_bitmap(matoran_matau, 40, 285, 0);

			al_draw_bitmap(matoran_onewa, 1400, 577, 0);
			al_draw_bitmap(matoran_onewa, 1530, 480, 0);
			al_draw_bitmap(matoran_onewa, 1400, 385, 0);
			al_draw_bitmap(matoran_onewa, 1530, 285, 0);
			al_flip_display();
		}

		//if (x > width) x = -al_get_bitmap_width(board);  don't need
		if (y > 50) y = 50;

	}

	al_destroy_display(display); 
	al_uninstall_keyboard();
	al_destroy_timer(timer);
	al_destroy_bitmap(board);
	al_destroy_bitmap(tas);
	al_destroy_bitmap(menu1);
	al_destroy_bitmap(menu2);
	al_destroy_bitmap(menu3);
	al_destroy_bitmap(matau);
	al_destroy_bitmap(onewa);
	al_destroy_bitmap(matoran_matau);
	al_destroy_bitmap(matoran_onewa);
	return 0;
}
