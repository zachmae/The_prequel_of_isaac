/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** buttons.h
*/

#ifndef BUTTONS_H_
#define BUTTONS_H_

void go_scene_game(struct core_s *core);
void go_scene_option(struct core_s *core);
void close_win(struct core_s *core);
void go_scene_menu(struct core_s *core);
void go_scene_pause(struct core_s *core);
void music_switcher(struct core_s *core);
void go_scene_cinematic(struct core_s *core);
void music_lower(struct core_s *core);
void music_upper(struct core_s *core);
void go_scene_cinematic(struct core_s *core);
void set_framerate_30(struct core_s *core);
void set_framerate_60(struct core_s *core);
void set_framerate_120(struct core_s *core);
void sfx_switcher(struct core_s *core);
void restart_game(struct core_s *core);
void go_scene_tuto(struct core_s *core);
void go_scene_dialog(struct core_s *core);
void go_scene_dialog_robot(struct core_s *core);
void go_scene_dialog_car(struct core_s *core);
void attack_up(struct core_s *core);
void speed_up(struct core_s *core);
void life_up(struct core_s *core);
void go_scene_dialog_popeye(struct core_s *core);
void player_died(struct core_s *core);
void music_start(scene_t *scene, char *scene_id, bool status, float volume);
void music_stop(scene_t *scene, char *scene_id, bool status);
void check_win(core_t *core);
void life_handle(core_t *core, float heart_width);
void go_scene_inventory(struct core_s *core);
void use_item_attack(core_t *core);
void use_item_speed(core_t *core);
void use_item_life(core_t *core);
void go_scene_credits(struct core_s *core);

typedef void (*callback) (struct core_s *);

static const callback wow[] = {
    &go_scene_game,
    &go_scene_option,
    &close_win,
    &go_scene_menu,
    &go_scene_pause,
    &music_switcher,
    &music_lower,
    &music_upper,
    &go_scene_cinematic,
    &set_framerate_30,
    &set_framerate_60,
    &set_framerate_120,
    &sfx_switcher,
    &restart_game,
    &go_scene_tuto,
    &go_scene_dialog,
    &go_scene_dialog_robot,
    &go_scene_dialog_car,
    &attack_up,
    &speed_up,
    &life_up,
    &go_scene_dialog_popeye,
    &use_item_attack,
    &use_item_speed,
    &use_item_life,
    NULL
};

#endif /* !BUTTONS_H_ */
