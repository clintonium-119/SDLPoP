/*
SDLPoP, a port/conversion of the DOS game Prince of Persia.
Copyright (C) 2013-2022  Dávid Nagy

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

The authors of this program may be contacted at https://forum.princed.org
*/

// SEG000.C
void far pop_main(void);
void __pascal far init_game_main(void);
void __pascal far start_game(void);
int __pascal far process_key(void);
void __pascal far play_frame(void);
void __pascal far draw_game_frame(void);
void __pascal far anim_tile_modif(void);
void load_sound_names(void);
void __pascal far load_sounds(int min_sound,int max_sound);
void __pascal far load_opt_sounds(int first,int last);
void __pascal far load_lev_spr(int level);
void __pascal far load_level(void);
void reset_level_unused_fields(bool loading_clean_level);
int __pascal far play_kid_frame(void);
void __pascal far play_guard_frame(void);
void __pascal far check_the_end(void);
void __pascal far check_fall_flo(void);
void __pascal far read_joyst_control(void);
void __pascal far draw_kid_hp(short curr_hp,short max_hp);
void __pascal far draw_guard_hp(short curr_hp,short max_hp);
void __pascal far add_life(void);
void __pascal far set_health_life(void);
void __pascal far draw_hp(void);
void __pascal far do_delta_hp(void);
void __pascal far play_sound(int sound_id);
void __pascal far play_next_sound(void);
void __pascal far check_sword_vs_sword(void);
void __pascal far load_chtab_from_file(int chtab_id,int resource,const char near *filename,int palette_bits);
void __pascal far free_all_chtabs_from(int first);
void __pascal far load_more_opt_graf(const char *filename);
int __pascal far do_paused(void);
void __pascal far read_keyb_control(void);
void __pascal far copy_screen_rect(const rect_type far *source_rect_ptr);
void __pascal far toggle_upside(void);
void __pascal far feather_fall(void);
int __pascal far parse_grmode(void);
void __pascal far gen_palace_wall_colors(void);
void __pascal far show_title(void);
void __pascal far transition_ltr(void);
void __pascal far release_title_images(void);
void __pascal far draw_full_image(enum full_image_id id);
void __pascal far load_kid_sprite(void);
void __pascal far save_game(void);
short __pascal far load_game(void);
void __pascal far clear_screen_and_sounds(void);
void __pascal far parse_cmdline_sound(void);
void __pascal far free_optional_sounds(void);
void free_all_sounds(void);
void load_all_sounds(void);
void __pascal far free_optsnd_chtab(void);
void __pascal far load_title_images(int bgcolor);
void __pascal far show_copyprot(int where);
void __pascal far show_loading(void);
void __pascal far show_quotes(void);
void show_splash(void);
#ifdef USE_QUICKSAVE
void check_quick_op(void);
void restore_room_after_quick_load(void);
#endif // USE_QUICKSAVE

// SEG001.C
int __pascal far proc_cutscene_frame(int wait_frames);
void __pascal far play_both_seq(void);
void __pascal far draw_proom_drects(void);
void __pascal far play_kid_seq(void);
void __pascal far play_opp_seq(void);
void __pascal far draw_princess_room_bg(void);
void __pascal far seqtbl_offset_shad_char(int seq_index);
void __pascal far seqtbl_offset_kid_char(int seq_index);
void __pascal far init_mouse_cu8(void);
void __pascal far init_mouse_go(void);
void __pascal far princess_crouching(void);
void __pascal far princess_stand(void);
void __pascal far init_princess_x156(void);
void __pascal far princess_lying(void);
void __pascal far init_princess_right(void);
void __pascal far init_ending_princess(void);
void __pascal far init_mouse_1(void);
void __pascal far init_princess(void);
void __pascal far init_vizier(void);
void __pascal far init_ending_kid(void);
void __pascal far cutscene_8(void);
void __pascal far cutscene_9(void);
void __pascal far end_sequence_anim(void);
void __pascal far time_expired(void);
void __pascal far cutscene_12(void);
void __pascal far cutscene_4(void);
void __pascal far cutscene_2_6(void);
void __pascal far pv_scene(void);
void __pascal far set_hourglass_state(int state);
int __pascal far hourglass_frame(void);
void __pascal far princess_room_torch(void);
void __pascal far draw_hourglass(void);
void __pascal far reset_cutscene(void);
void __pascal far do_flash(short color);
void delay_ticks(Uint32 ticks);
void __pascal far remove_flash(void);
void __pascal far end_sequence(void);
void __pascal far expired(void);
void __pascal far load_intro(int which_imgs,void far (*func)(void),int free_sounds);
void __pascal far draw_star(int which_star,int mark_dirty);
void __pascal far show_hof(void);
void __pascal far hof_write(void);
void __pascal far hof_read(void);
void __pascal far show_hof_text(rect_type far *rect,int x_align,int y_align, const char *text);
int __pascal far fade_in_1(void);
int __pascal far fade_out_1(void);

// SEG002.C
void __pascal far do_init_shad(const byte *source,int seq_index);
void __pascal far get_guard_hp(void);
void __pascal far check_shadow(void);
void __pascal far enter_guard(void);
void __pascal far check_guard_fallout(void);
void __pascal far leave_guard(void);
void __pascal far follow_guard(void);
void __pascal far exit_room(void);
int __pascal far goto_other_room(short direction);
short __pascal far leave_room(void);
void __pascal far Jaffar_exit(void);
void __pascal far level3_set_chkp(void);
void __pascal far sword_disappears(void);
void __pascal far meet_Jaffar(void);
void __pascal far play_mirr_mus(void);
void __pascal far move_0_nothing(void);
void __pascal far move_1_forward(void);
void __pascal far move_2_backward(void);
void __pascal far move_3_up(void);
void __pascal far move_4_down(void);
void __pascal far move_up_back(void);
void __pascal far move_down_back(void);
void __pascal far move_down_forw(void);
void __pascal far move_6_shift(void);
void __pascal far move_7(void);
void __pascal far autocontrol_opponent(void);
void __pascal far autocontrol_mouse(void);
void __pascal far autocontrol_shadow(void);
void __pascal far autocontrol_skeleton(void);
void __pascal far autocontrol_Jaffar(void);
void __pascal far autocontrol_kid(void);
void __pascal far autocontrol_guard(void);
void __pascal far autocontrol_guard_inactive(void);
void __pascal far autocontrol_guard_active(void);
void __pascal far autocontrol_guard_kid_far(void);
void __pascal far guard_follows_kid_down(void);
void __pascal far autocontrol_guard_kid_in_sight(short distance);
void __pascal far autocontrol_guard_kid_armed(short distance);
void __pascal far guard_advance(void);
void __pascal far guard_block(void);
void __pascal far guard_strike(void);
void __pascal far hurt_by_sword(void);
void __pascal far check_sword_hurt(void);
void __pascal far check_sword_hurting(void);
void __pascal far check_hurting(void);
void __pascal far check_skel(void);
void __pascal far do_auto_moves(const auto_move_type *moves_ptr);
void __pascal far autocontrol_shadow_level4(void);
void __pascal far autocontrol_shadow_level5(void);
void __pascal far autocontrol_shadow_level6(void);
void __pascal far autocontrol_shadow_level12(void);

// SEG003.C
void __pascal far init_game(int level);
void __pascal far play_level(int level_number);
void __pascal far do_startpos(void);
void __pascal far set_start_pos(void);
void __pascal far find_start_level_door(void);
void __pascal far draw_level_first(void);
void __pascal far redraw_screen(int drawing_different_room);
int __pascal far play_level_2(void);
void __pascal far redraw_at_char(void);
void __pascal far redraw_at_char2(void);
void __pascal far check_knock(void);
void __pascal far timers(void);
void __pascal far check_mirror(void);
void __pascal far jump_through_mirror(void);
void __pascal far check_mirror_image(void);
void __pascal far bump_into_opponent(void);
void __pascal far pos_guards(void);
void __pascal far check_can_guard_see_kid(void);
byte __pascal far get_tile_at_kid(int xpos);
void __pascal far do_mouse(void);
int __pascal far flash_if_hurt(void);
void __pascal far remove_flash_if_hurt(void);

// SEG004.C
void __pascal far check_collisions(void);
void __pascal far move_coll_to_prev(void);
void __pascal far get_row_collision_data(short row,sbyte *row_coll_room_ptr,byte *row_coll_flags_ptr);
int __pascal far get_left_wall_xpos(int room,int column,int row);
int __pascal far get_right_wall_xpos(int room,int column,int row);
void __pascal far check_bumped(void);
void __pascal far check_bumped_look_left(void);
void __pascal far check_bumped_look_right(void);
int __pascal far is_obstacle_at_col(int tile_col);
int __pascal far is_obstacle(void);
int __pascal far xpos_in_drawn_room(int xpos);
void __pascal far bumped(sbyte delta_x,sbyte direction);
void __pascal far bumped_fall(void);
void __pascal far bumped_floor(sbyte direction);
void __pascal far bumped_sound(void);
void __pascal far clear_coll_rooms(void);
int __pascal far can_bump_into_gate(void);
int __pascal far get_edge_distance(void);
void __pascal far check_chomped_kid(void);
void __pascal far chomped(void);
void __pascal far check_gate_push(void);
void __pascal far check_guard_bumped(void);
void __pascal far check_chomped_guard(void);
int __pascal far check_chomped_here(void);
int __pascal far dist_from_wall_forward(byte tiletype);
int __pascal far dist_from_wall_behind(byte tiletype);

// SEG005.C
void __pascal far seqtbl_offset_char(short seq_index);
void __pascal far seqtbl_offset_opp(int seq_index);
void __pascal far do_fall(void);
void __pascal far land(void);
void __pascal far spiked(void);
void __pascal far control(void);
void __pascal far control_crouched(void);
void __pascal far control_standing(void);
void __pascal far up_pressed(void);
void __pascal far down_pressed(void);
void __pascal far go_up_leveldoor(void);
void __pascal far control_turning(void);
void __pascal far crouch(void);
void __pascal far back_pressed(void);
void __pascal far forward_pressed(void);
void __pascal far control_running(void);
void __pascal far safe_step(void);
int __pascal far check_get_item(void);
void __pascal far get_item(void);
void __pascal far control_startrun(void);
void __pascal far control_jumpup(void);
void __pascal far standing_jump(void);
void __pascal far check_jump_up(void);
void __pascal far jump_up_or_grab(void);
void __pascal far grab_up_no_floor_behind(void);
void __pascal far jump_up(void);
void __pascal far control_hanging(void);
void __pascal far can_climb_up(void);
void __pascal far hang_fall(void);
void __pascal far grab_up_with_floor_behind(void);
void __pascal far run_jump(void);
void __pascal far back_with_sword(void);
void __pascal far forward_with_sword(void);
void __pascal far draw_sword(void);
void __pascal far control_with_sword(void);
void __pascal far swordfight(void);
void __pascal far sword_strike(void);
void __pascal far parry(void);

// SEG006.C
int __pascal far get_tile(int room,int col,int row);
int __pascal far find_room_of_tile(void);
int __pascal far get_tilepos(int tile_col,int tile_row);
int __pascal far get_tilepos_nominus(int tile_col,int tile_row);
void __pascal far load_fram_det_col(void);
void __pascal far determine_col(void);
void __pascal far load_frame(void);
short __pascal far dx_weight(void);
int __pascal far char_dx_forward(int delta_x);
int __pascal far obj_dx_forward(int delta_x);
void __pascal far play_seq(void);
int __pascal far get_tile_div_mod_m7(int xpos);
int __pascal far get_tile_div_mod(int xpos);
int __pascal far sub_70B6(int ypos);
int __pascal far y_to_row_mod4(int ypos);
void __pascal far loadkid(void);
void __pascal far savekid(void);
void __pascal far loadshad(void);
void __pascal far saveshad(void);
void __pascal far loadkid_and_opp(void);
void __pascal far savekid_and_opp(void);
void __pascal far loadshad_and_opp(void);
void __pascal far saveshad_and_opp(void);
void __pascal far reset_obj_clip(void);
void __pascal far x_to_xh_and_xl(int xpos, sbyte *xh_addr, sbyte *xl_addr);
void __pascal far fall_accel(void);
void __pascal far fall_speed(void);
void __pascal far check_action(void);
int __pascal far tile_is_floor(int tiletype);
void __pascal far check_spiked(void);
int __pascal far take_hp(int count);
int __pascal far get_tile_at_char(void);
void __pascal far set_char_collision(void);
void __pascal far check_on_floor(void);
void __pascal far start_fall(void);
void __pascal far check_grab(void);
int __pascal far can_grab_front_above(void);
void __pascal far in_wall(void);
int __pascal far get_tile_infrontof_char(void);
int __pascal far get_tile_infrontof2_char(void);
int __pascal far get_tile_behind_char(void);
int __pascal far distance_to_edge_weight(void);
int __pascal far distance_to_edge(int xpos);
void __pascal far fell_out(void);
void __pascal far play_kid(void);
void __pascal far control_kid(void);
void __pascal far do_demo(void);
void __pascal far play_guard(void);
void __pascal far user_control(void);
void __pascal far flip_control_x(void);
int __pascal far release_arrows(void);
void __pascal far save_ctrl_1(void);
void __pascal far rest_ctrl_1(void);
void __pascal far clear_saved_ctrl(void);
void __pascal far read_user_control(void);
int __pascal far can_grab(void);
int __pascal far wall_type(byte tiletype);
int __pascal far get_tile_above_char(void);
int __pascal far get_tile_behind_above_char(void);
int __pascal far get_tile_front_above_char(void);
int __pascal far back_delta_x(int delta_x);
void __pascal far do_pickup(int obj_type);
void __pascal far check_press(void);
void __pascal far check_spike_below(void);
void __pascal far clip_char(void);
void __pascal far stuck_lower(void);
void __pascal far set_objtile_at_char(void);
void __pascal far proc_get_object(void);
int __pascal far is_dead(void);
void __pascal far play_death_music(void);
void __pascal far on_guard_killed(void);
void __pascal far clear_char(void);
void __pascal far save_obj(void);
void __pascal far load_obj(void);
void __pascal far draw_hurt_splash(void);
void __pascal far check_killed_shadow(void);
void __pascal far add_sword_to_objtable(void);
void __pascal far control_guard_inactive(void);
int __pascal far char_opp_dist(void);
void __pascal far inc_curr_row(void);

// SEG007.C
void __pascal far process_trobs(void);
void __pascal far animate_tile(void);
short __pascal far is_trob_in_drawn_room(void);
void __pascal far set_redraw_anim_right(void);
void __pascal far set_redraw_anim_curr(void);
void __pascal far redraw_at_trob(void);
void __pascal far redraw_21h(void);
void __pascal far redraw_11h(void);
void __pascal far redraw_20h(void);
void __pascal far draw_trob(void);
void __pascal far redraw_tile_height(void);
short __pascal far get_trob_pos_in_drawn_room(void);
short __pascal far get_trob_right_pos_in_drawn_room(void);
short __pascal far get_trob_right_above_pos_in_drawn_room(void);
void __pascal far animate_torch(void);
void __pascal far animate_potion(void);
void __pascal far animate_sword(void);
void __pascal far animate_chomper(void);
void __pascal far animate_spike(void);
void __pascal far animate_door(void);
void __pascal far gate_stop(void);
void __pascal far animate_leveldoor(void);
short __pascal far bubble_next_frame(short curr);
short __pascal far get_torch_frame(short curr);
void __pascal far set_redraw_anim(short tilepos,byte frames);
void __pascal far set_redraw2(short tilepos,byte frames);
void __pascal far set_redraw_floor_overlay(short tilepos, byte frames);
void __pascal far set_redraw_full(short tilepos,byte frames);
void __pascal far set_redraw_fore(short tilepos,byte frames);
void __pascal far set_wipe(short tilepos,byte frames);
void __pascal far start_anim_torch(short room,short tilepos);
void __pascal far start_anim_potion(short room,short tilepos);
void __pascal far start_anim_sword(short room,short tilepos);
void __pascal far start_anim_chomper(short room,short tilepos, byte modifier);
void __pascal far start_anim_spike(short room,short tilepos);
short __pascal far trigger_gate(short room,short tilepos,short button_type);
short __pascal far trigger_1(short target_type,short room,short tilepos,short button_type);
void __pascal far do_trigger_list(short index,short button_type);
void __pascal far add_trob(byte room,byte tilepos,sbyte type);
short __pascal far find_trob(void);
void __pascal far clear_tile_wipes(void);
short __pascal far get_doorlink_timer(short index);
short __pascal far set_doorlink_timer(short index,byte value);
short __pascal far get_doorlink_tile(short index);
short __pascal far get_doorlink_next(short index);
short __pascal far get_doorlink_room(short index);
void __pascal far trigger_button(int playsound,int button_type,int modifier);
void __pascal far died_on_button(void);
void __pascal far animate_button(void);
void __pascal far start_level_door(short room,short tilepos);
void __pascal far animate_empty(void);
void __pascal far animate_loose(void);
void __pascal far loose_shake(int arg_0);
int __pascal far remove_loose(int room, int tilepos);
void __pascal far make_loose_fall(byte modifier);
void __pascal far start_chompers(void);
int __pascal far next_chomper_timing(byte timing);
void __pascal far loose_make_shake(void);
void __pascal far do_knock(int room,int tile_row);
void __pascal far add_mob(void);
short __pascal far get_curr_tile(short tilepos);
void __pascal far do_mobs(void);
void __pascal far move_mob(void);
void __pascal far move_loose(void);
void __pascal far loose_land(void);
void __pascal far loose_fall(void);
void __pascal far redraw_at_cur_mob(void);
void __pascal far mob_down_a_row(void);
void __pascal far draw_mobs(void);
void __pascal far draw_mob(void);
void __pascal far add_mob_to_objtable(int ypos);
void __pascal far sub_9A8E(void);
int __pascal far is_spike_harmful(void);
void __pascal far check_loose_fall_on_kid(void);
void __pascal far fell_on_your_head(void);
void __pascal far play_door_sound_if_visible(int sound_id);

// SEG008.C
void __pascal far redraw_room(void);
void __pascal far load_room_links(void);
void __pascal far draw_room(void);
void __pascal far draw_tile(void);
void __pascal far draw_tile_aboveroom(void);
void __pascal far redraw_needed(short tilepos);
void __pascal far redraw_needed_above(int column);
int __pascal far get_tile_to_draw(int room, int column, int row, byte *ptr_tile, byte *ptr_modifier, byte tile_room0);
void __pascal far load_curr_and_left_tile(void);
void __pascal far load_leftroom(void);
void __pascal far load_rowbelow(void);
void __pascal far draw_tile_floorright(void);
int __pascal far can_see_bottomleft(void);
void __pascal far draw_tile_topright(void);
void __pascal far draw_tile_anim_topright(void);
void __pascal far draw_tile_right(void);
int __pascal far get_spike_frame(byte modifier);
void __pascal far draw_tile_anim_right(void);
void __pascal far draw_tile_bottom(word arg_0);
void __pascal far draw_loose(int arg_0);
void __pascal far draw_tile_base(void);
void __pascal far draw_tile_anim(void);
void __pascal far draw_tile_fore(void);
int __pascal far get_loose_frame(byte modifier);
int __pascal far add_backtable(short chtab_id, int id, sbyte xh, sbyte xl, int ybottom, int blit, byte peel);
int __pascal far add_foretable(short chtab_id, int id, sbyte xh, sbyte xl, int ybottom, int blit, byte peel);
int __pascal far add_midtable(short chtab_id, int id, sbyte xh, sbyte xl, int ybottom, int blit, byte peel);
void __pascal far add_peel(int left,int right,int top,int height);
void __pascal far add_wipetable(sbyte layer,short left,short bottom,sbyte height,short width,sbyte color);
void __pascal far draw_table(int which_table);
void __pascal far draw_wipes(int which);
void __pascal far draw_back_fore(int which_table,int index);
void __pascal far draw_mid(int index);
void __pascal far draw_image(image_type far *image,image_type far *mask,int xpos,int ypos,int blit);
void __pascal far draw_wipe(int index);
void __pascal far calc_gate_pos(void);
void __pascal far draw_gate_back(void);
void __pascal far draw_gate_fore(void);
void __pascal far alter_mods_allrm(void);
void __pascal far load_alter_mod(int tile_ix);
void __pascal far draw_moving(void);
void __pascal far redraw_needed_tiles(void);
void __pascal far draw_tile_wipe(byte height);
void __pascal far draw_tables(void);
void __pascal far restore_peels(void);
void __pascal far add_drect(rect_type *source);
void __pascal far draw_leveldoor(void);
void __pascal far get_room_address(int room);
void __pascal far draw_floor_overlay(void);
void __pascal far draw_other_overlay(void);
void __pascal far draw_tile2(void);
void __pascal far draw_objtable_items_at_tile(byte tilepos);
void __pascal far sort_curr_objs(void);
int __pascal far compare_curr_objs(int index1,int index2);
void __pascal far draw_objtable_item(int index);
int __pascal far load_obj_from_objtable(int index);
void __pascal far draw_people(void);
void __pascal far draw_kid(void);
void __pascal far draw_guard(void);
void __pascal far add_kid_to_objtable(void);
void __pascal far add_guard_to_objtable(void);
void __pascal far add_objtable(byte obj_type);
void __pascal far mark_obj_tile_redraw(int index);
void __pascal far load_frame_to_obj(void);
void __pascal far show_time(void);
void __pascal far show_level(void);
short __pascal far calc_screen_x_coord(short logical_x);
void __pascal far free_peels(void);
void __pascal far display_text_bottom(const char near *text);
void __pascal far erase_bottom_text(int arg_0);
void __pascal far wall_pattern(int which_part,int which_table);
void __pascal far draw_left_mark (word arg3, word arg2, word arg1);
void __pascal far draw_right_mark (word arg2, word arg1);
image_type* get_image(short chtab_id, int id);

// SEG009.C
void sdlperror(const char* header);
bool file_exists(const char* filename);
#define locate_file(filename) locate_file_(filename, alloca(POP_MAX_PATH), POP_MAX_PATH)
const char* locate_file_(const char* filename, char* path_buffer, int buffer_size);

#ifdef _WIN32

FILE* fopen_UTF8(const char* filename, const char* mode);
#define fopen fopen_UTF8

int chdir_UTF8(const char* path);
#define chdir chdir_UTF8

int mkdir_UTF8(const char* path);
#define mkdir mkdir_UTF8

int access_UTF8(const char* filename_UTF8, int mode);
#ifdef access
#undef access
#endif
#define access access_UTF8

int stat_UTF8(const char *filename_UTF8, struct stat *_Stat);
// We define a function-like macro, because `stat` is also the name of the type, and we don't want to redefine that.
#define stat(filename_UTF8, _Stat) stat_UTF8(filename_UTF8, _Stat)

#endif //_WIN32

directory_listing_type* create_directory_listing_and_find_first_file(const char* directory, const char* extension);
char* get_current_filename_from_directory_listing(directory_listing_type* data);
bool find_next_file(directory_listing_type* data);
void close_directory_listing(directory_listing_type* data);
int __pascal far read_key(void);
void __pascal far clear_kbd_buf(void);
word __pascal far prandom(word max);
int __pascal far round_xpos_to_byte(int xpos,int round_direction);
void __pascal far show_dialog(const char *text);
void __pascal far quit(int exit_code);
void __pascal far restore_stuff(void);
int __pascal far key_test_quit(void);
const char* __pascal far check_param(const char *param);
int __pascal far pop_wait(int timer_index,int time);
dat_type *__pascal open_dat(const char *file, int optional);
void __pascal far set_loaded_palette(dat_pal_type far *palette_ptr);
chtab_type* __pascal load_sprites_from_file(int resource,int palette_bits, int quit_on_error);
void __pascal far free_chtab(chtab_type *chtab_ptr);
image_type* decode_image(image_data_type* image_data, dat_pal_type* palette);
image_type*far __pascal far load_image(int index, dat_pal_type* palette);
void __pascal far draw_image_transp(image_type far *image,image_type far *mask,int xpos,int ypos);
int __pascal far set_joy_mode(void);
surface_type far *__pascal make_offscreen_buffer(const rect_type far *rect);
void __pascal far free_surface(surface_type *surface);
void __pascal far free_peel(peel_type *peel_ptr);
void __pascal far set_hc_pal(void);
void __pascal far flip_not_ega(byte far *memory,int height,int stride);
void __pascal far flip_screen(surface_type far *surface);
void __pascal far fade_in_2(surface_type near *source_surface,int which_rows);
void __pascal far fade_out_2(int rows);
void __pascal far draw_image_transp_vga(image_type far *image,int xpos,int ypos);
int __pascal far get_line_width(const char far *text,int length);
int __pascal far draw_text_character(byte character);
void __pascal far draw_rect(const rect_type far *rect,int color);
void draw_rect_with_alpha(const rect_type* rect, byte color, byte alpha);
void draw_rect_contours(const rect_type* rect, byte color);
surface_type far *__pascal rect_sthg(surface_type *surface,const rect_type far *rect);
rect_type far *__pascal shrink2_rect(rect_type far *target_rect,const rect_type far *source_rect,int delta_x,int delta_y);
void __pascal far set_curr_pos(int xpos,int ypos);
void __pascal far restore_peel(peel_type *peel_ptr);
peel_type* __pascal far read_peel_from_screen(const rect_type far *rect);
void __pascal far show_text(const rect_type far *rect_ptr,int x_align,int y_align,const char far *text);
int __pascal far intersect_rect(rect_type far *output,const rect_type far *input1,const rect_type far *input2);
rect_type far * __pascal far union_rect(rect_type far *output,const rect_type far *input1,const rect_type far *input2);
void __pascal far stop_sounds(void);
void init_digi(void);
void __pascal far play_sound_from_buffer(sound_buffer_type far *buffer);
void turn_music_on_off(byte new_state);
void __pascal far turn_sound_on_off(byte new_state);
int __pascal far check_sound_playing(void);
void apply_aspect_ratio(void);
void window_resized(void);
void __pascal far set_gr_mode(byte grmode);
SDL_Surface* get_final_surface(void);
void update_screen(void);
void __pascal far set_pal_arr(int start,int count,const rgb_type far *array,int vsync);
void __pascal far set_pal(int index,int red,int green,int blue,int vsync);
int __pascal far add_palette_bits(byte n_colors);
void __pascal far process_palette(void *target,dat_pal_type far *source);
int __pascal far find_first_pal_row(int which_rows_mask);
int __pascal far get_text_color(int cga_color,int low_half,int high_half_mask);
void __pascal far close_dat(dat_type far *pointer);
void far *__pascal load_from_opendats_alloc(int resource, const char* extension, data_location* out_result, int* out_size);
int __pascal far load_from_opendats_to_area(int resource,void far *area,int length, const char* extension);
void rect_to_sdlrect(const rect_type* rect, SDL_Rect* sdlrect);
void __pascal far method_1_blit_rect(surface_type near *target_surface,surface_type near *source_surface,const rect_type far *target_rect, const rect_type far *source_rect,int blit);
image_type far * __pascal far method_3_blit_mono(image_type far *image,int xpos,int ypos,int blitter,byte color);
const rect_type far * __pascal far method_5_rect(const rect_type far *rect,int blit,byte color);
void draw_rect_with_alpha(const rect_type* rect, byte color, byte alpha);
image_type far * __pascal far method_6_blit_img_to_scr(image_type far *image,int xpos,int ypos,int blit);
void reset_timer(int timer_index);
double get_ticks_per_sec(int timer_index);
void set_timer_length(int timer_index, int length);
void __pascal start_timer(int timer_index, int length);
int __pascal do_wait(int timer_index);
void __pascal far init_timer(int frequency);
void __pascal far set_clip_rect(const rect_type far *rect);
void __pascal far reset_clip_rect(void);
void __pascal far set_bg_attr(int vga_pal_index,int hc_pal_index);
rect_type far *__pascal offset4_rect_add(rect_type far *dest, const rect_type far *source,int d_left,int d_top,int d_right,int d_bottom);
int __pascal far input_str(const rect_type far *rect,char *buffer,int max_length,const char *initial,int has_initial,int arg_4,int color,int bgcolor);
rect_type far *__pascal offset2_rect(rect_type far *dest, const rect_type far *source,int delta_x,int delta_y);
void __pascal far show_text_with_color(const rect_type far *rect_ptr,int x_align,int y_align, const char far *text,int color);
void __pascal do_simple_wait(int timer_index);
void process_events(void);
void idle(void);
void __pascal far init_copyprot_dialog(void);
dialog_type * __pascal far make_dialog_info(dialog_settings_type *settings, rect_type *dialog_rect,
                                            rect_type *text_rect, peel_type *dialog_peel);
void __pascal far calc_dialog_peel_rect(dialog_type*dialog);
void __pascal far read_dialog_peel(dialog_type *dialog);
void __pascal far draw_dialog_frame(dialog_type *dialog);
void __pascal far add_dialog_rect(dialog_type *dialog);
void __pascal far dialog_method_2_frame(dialog_type *dialog);
#ifdef USE_FADE
void __pascal far fade_in_2(surface_type near *source_surface,int which_rows);
palette_fade_type far *__pascal make_pal_buffer_fadein(surface_type *source_surface,int which_rows,int wait_time);
void __pascal far pal_restore_free_fadein(palette_fade_type far *palette_buffer);
int __pascal far fade_in_frame(palette_fade_type far *palette_buffer);
void __pascal far fade_out_2(int rows);
palette_fade_type far *__pascal make_pal_buffer_fadeout(int which_rows,int wait_time);
void __pascal far pal_restore_free_fadeout(palette_fade_type far *palette_buffer);
int __pascal far fade_out_frame(palette_fade_type far *palette_buffer);
void __pascal far read_palette_256(rgb_type far *target);
void __pascal far set_pal_256(rgb_type far *source);
#endif
void set_chtab_palette(chtab_type* chtab, byte* colors, int n_colors);
int has_timer_stopped(int index);
sound_buffer_type* load_sound(int index);
void free_sound(sound_buffer_type far *buffer);

// SEQTABLE.C
void apply_seqtbl_patches(void);
#ifdef CHECK_SEQTABLE_MATCHES_ORIGINAL
void check_seqtable_matches_original();
#endif

// OPTIONS.C
void turn_fixes_and_enhancements_on_off(byte new_state);
void turn_custom_options_on_off(byte new_state);
void set_options_to_default(void);
void load_global_options(void);
void check_mod_param(void);
void load_mod_options(void);
int process_rw_write(SDL_RWops* rw, void* data, size_t data_size);
int process_rw_read(SDL_RWops* rw, void* data, size_t data_size);
void load_dos_exe_modifications(const char* folder_name);

// REPLAY.C
#ifdef USE_REPLAY
void start_with_replay_file(const char *filename);
void init_record_replay(void);
void replay_restore_level(void);
int restore_savestate_from_buffer(void);
void start_recording(void);
void add_replay_move(void);
void stop_recording(void);
void start_replay(void);
void end_replay(void);
void do_replay_move(void);
int save_recorded_replay_dialog(void);
int save_recorded_replay(const char* full_filename);
void replay_cycle(void);
int load_replay(void);
void key_press_while_recording(int* key_ptr);
void key_press_while_replaying(int* key_ptr);
#endif

// lighting.c
#ifdef USE_LIGHTING
void init_lighting(void);
void redraw_lighting(void);
void update_lighting(const rect_type far *source_rect_ptr);
#endif

// screenshot.c
#ifdef USE_SCREENSHOT
void save_screenshot(void);
void auto_screenshot(void);
bool want_auto_screenshot(void);
void init_screenshot(void);
void save_level_screenshot(bool want_extras);
#endif

// menu.c
#ifdef USE_MENU
void init_menu(void);
void menu_scroll(int y);
void draw_menu(void);
void clear_menu_controls(void);
void process_additional_menu_input(void);
int key_test_paused_menu(int key);
void load_ingame_settings(void);
void menu_was_closed(void);
#endif

// midi.c
void stop_midi(void);
void init_midi(void);
void midi_callback(void *userdata, Uint8 *stream, int len);
void __pascal far play_midi_sound(sound_buffer_type far *buffer);
