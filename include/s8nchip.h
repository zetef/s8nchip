#pragma once

#include <SDL.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_GFX 64 * 32
#define MAX_KEY 16
#define MAX_MEMORY 4096
#define MAX_V_REGISTERS 16
#define MAX_STACKS 16
#define INTERPRETER_MEMORY_END 0x200
#define FONTSET_SIZE 80

struct chip
{
    bool drawFlag; //doar 0x00E0(clear screen) si 0xDXYN(draw sprite to screen) seteaza flagul true
    uint32_t gfx[ MAX_GFX ];
    uint8_t key[ MAX_KEY ]; //0xF

    uint8_t memory[ MAX_MEMORY ];
    uint8_t V[ MAX_V_REGISTERS ];

    uint16_t stack[ MAX_STACKS ];
    uint16_t sp;

    uint16_t I;
    uint16_t pc;
	uint16_t opcode;

	uint8_t delayTimer;
    uint8_t soundTimer;

	//char *chipName; //for later versions, and when this interpreter will actualy work
};

void chip_initialize( struct chip *cpu );
bool chip_loadGame( struct chip *cpu, const char *filename );
void chip_handleInput( struct chip *cpu, SDL_Event *event );
void chip_fetch( struct chip *cpu );
void chip_execute( struct chip *cpu );
void chip_update_timers( struct chip *cpu );
void chip_cycle( struct chip *cpu );
void chip_free( struct chip *cpu );