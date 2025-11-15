CPP_FILES="menu_function.cpp main.cpp menu_items.cpp"
APP=example

if [ -f $APP ]; then rm $APP
fi

g++ $CPP_FILES -o $APP

./$APP