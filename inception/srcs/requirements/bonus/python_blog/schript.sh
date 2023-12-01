#!/bin/bash
rm -rf venv
rm -rf main.py
cp ../main.py .
export SECRET_KEY=$SECRET_KEY
python3 -m venv venv
source venv/bin/activate
pip3 install -r requirements.txt
python3 main.py
