cmake_minimum_required(VERSION 3.14)
project(cass_lion CXX)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

find_package(PostgreSQL REQUIRED)
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM3 REQUIRED gtkmm-3.0)

INCLUDE_DIRECTORIES(${PostgreSQL_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GTKMM3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM3_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} main.cpp
        MainWindow.cpp MainWindow.h
        AbstractKeyEventedWindow.cpp AbstractKeyEventedWindow.h
        KeyCombination.cpp KeyCombination.h
        AbstractWindowWithShortcuts.cpp AbstractWindowWithShortcuts.h
        Database/AbstractDatabaseDriver.cpp Database/AbstractDatabaseDriver.h
        Database/PostgreSql/PostgreSqlDriver.cpp
        Database/PostgreSql/PostgreSqlDriver.h
        Database/AbstractDatabaseConfiguration.cpp
        Database/AbstractDatabaseConfiguration.h
        Database/AbstractDatabaseConnectionPool.cpp Database/AbstractDatabaseConnectionPool.h Database/AbstractDatabaseConnection.cpp Database/AbstractDatabaseConnection.h Database/PostgreSql/PostgresqlDatabaseConfiguration.cpp Database/PostgreSql/PostgresqlDatabaseConfiguration.h Database/PostgreSql/PostgreSqlConnection.cpp Database/PostgreSql/PostgreSqlConnection.h Exceptions/Exception.cpp Exceptions/Exception.h Database/Exceptions/DatabaseDriverException.cpp Database/Exceptions/DatabaseDriverException.h Database/Exceptions/DatabaseConnectionRefusedException.cpp Database/Exceptions/DatabaseConnectionRefusedException.h)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PostgreSQL_LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTKMM3_LIBRARIES})


