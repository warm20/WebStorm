clear
if [ "$1" = "-r" ]; then
    echo "--Complie for Release"
    g++ ./WebStorm/SEngine/HttpReq.cpp \
        ./WebStorm/SEngine/SEngine.cpp \
        ./WebStorm/SEngine/UrlParse.cpp \
        ./WebStorm/SEngine/General.cpp \
        $2 \
        -o ./build/Release/a.out \
        -std=c++20
elif [ "$1" = "-t" ]; then
    echo "--Complie for Test"
    g++ $2 \
        -o ./build/Test/a.out \
        -std=c++20
fi

if [ "$3" = "-run" ]; then
    echo "[ --Run-- ]"
    if [ "$1" = "-r" ]; then
        ./build/Release/a.out
    elif [ "$1" = "-t" ]; then
        ./build/Test/a.out
fi
fi