
## 源文件类型
SRCEXTS := .c .cc .cpp .cxx

## 指定C/C++编译器
CC 		:= gcc
CXX 	:= g++
LINK 	:= g++

## 编译器选项
CFLAGS 		:= -Wall -fPIC
CXXFLAGS 	:= --std=c++11 -Wall -fPIC
MYCFLAGS 	:= -DDEBUG

ROOT=$(shell pwd)

BASE_DIR=$(ROOT)/base

## DEBUG开关选项
DEBUG   := 1

## 头文件搜索路径
INCPATH ?= -I. -I$(BASE_DIR) -I$(ROOT)/data_structures

## 源代码子目录
SRCDIRS := sample

## 可执行目标程序
TARGETS = list_sample 

ifeq ($(DEBUG), 1)
	    CXXFLAGS += -g
	else
	    CXXFLAGS += -O2
	endif

## 库文件
LIBS = -lm

.PHONY: clean
	.SUFFIXES:

all: $(TARGETS)

list_sample: $(SRCDIRS)/list.cpp
	    $(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)
		
#-------------------------------------
clean:
	-rm -f *~ core *.core
	-rm -f $(TARGETS)
	-rm -rf *.dSYM

