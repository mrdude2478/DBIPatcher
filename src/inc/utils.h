/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 *
 * Created on 9. září 2025, 14:28
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

//int mkpath(mode_t mode, const char* fmt, ...);
int mkpath(int mode, const char *fmt, ...);
int mkpath_for_file(int mode, const char *filepath);

#endif /* UTILS_H */

