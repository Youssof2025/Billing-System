#!/bin/bash
clear
gcc BillingSystem.c
mv a.out Customer_Logs
cd Customer_Logs
./a.out
rm a.out