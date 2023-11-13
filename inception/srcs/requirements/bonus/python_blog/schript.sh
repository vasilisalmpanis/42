#!/bin/bash
rm -rf venv
export SECRET_KEY=$SECRET_KEY
python3 -m venv venv
source venv/bin/activate
pip3 install -r requirements.txt
python3 main.py
