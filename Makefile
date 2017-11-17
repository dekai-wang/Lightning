
## 源文件类型
SRCEXTS := .c .cc .cpp .cxx

## 指定C/C++编译器
CXX 	:= g++
LINK 	:= g++

## 编译器选项
CXXFLAGS 	:= --std=c++11 -Wall -fPIC
MYCFLAGS 	:= -DDEBUG

ROOT=$(shell pwd)

## DEBUG开关选项
DEBUG   := 1

## 头文件搜索路径
INCPATH ?= -I. -I$(ROOT)/base -I$(ROOT)/data_structures

## 源代码子目录
SRCDIRS := sample

## 可执行目标程序
TARGETS = bstree_sample

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

queue_sample: $(SRCDIRS)/queue.cpp
	    $(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

stack_sample: $(SRCDIRS)/stack.cpp
	    $(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

bstree_sample: $(SRCDIRS)/bstree.cpp
	    $(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)
		
#-------------------------------------
clean:
	-rm -f *~ core *.core
	-rm -f $(TARGETS)
	-rm -rf *.dSYM

