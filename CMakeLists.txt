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
        Windows/MainWindow.cpp Windows/MainWindow.h
        AbstractKeyEventedWindow.cpp AbstractKeyEventedWindow.h
        KeyCombination.cpp KeyCombination.h
        AbstractWindowWithShortcuts.cpp AbstractWindowWithShortcuts.h
        Database/AbstractDatabaseDriver.cpp Database/AbstractDatabaseDriver.h
        Database/PostgreSql/PostgreSqlDriver.cpp
        Database/PostgreSql/PostgreSqlDriver.h
        Database/AbstractDatabaseConfiguration.cpp
        Database/AbstractDatabaseConfiguration.h
        Database/AbstractDatabaseConnectionPool.cpp Database/AbstractDatabaseConnectionPool.h
        Database/AbstractDatabaseConnection.cpp Database/AbstractDatabaseConnection.h
        Database/PostgreSql/PostgreSqlDatabaseConfiguration.cpp Database/PostgreSql/PostgreSqlDatabaseConfiguration.h
        Database/PostgreSql/PostgreSqlConnection.cpp Database/PostgreSql/PostgreSqlConnection.h
        Exceptions/Exception.cpp Exceptions/Exception.h
        Database/Exceptions/DatabaseDriverException.cpp Database/Exceptions/DatabaseDriverException.h
        Database/Exceptions/DatabaseConnectionRefusedException.cpp Database/Exceptions/DatabaseConnectionRefusedException.h
        Database/AbstractDatabaseQuery.cpp Database/AbstractDatabaseQuery.h
        Database/PostgreSql/PostgreSqlQuery.cpp Database/PostgreSql/PostgreSqlQuery.h
        Async/AbstractBackgroundExecutor.cpp Async/AbstractBackgroundExecutor.h
        Async/AbstractTask.cpp Async/AbstractTask.h
        Async/Exceptions/BackgroundExecutorAlreadyBusy.cpp Async/Exceptions/BackgroundExecutorAlreadyBusy.h
        Async/AsyncCallback.h
        Database/QueryResultCallback.cpp Database/QueryResultCallback.h
        ApplicationContext.cpp ApplicationContext.h
        Windows/DatabaseConnectionStatusWidget.cpp
        Windows/DatabaseConnectionStatusWidget.h
        Database/AbstractDatabasePatch.cpp Database/AbstractDatabasePatch.h
        Database/PostgreSql/Patches/InitialPatch.cpp Database/PostgreSql/Patches/InitialPatch.h
        Database/Exceptions/QueryExecuteException.cpp Database/Exceptions/QueryExecuteException.h
        Database/PostgreSql/PostgreSqlDatabasePatcher.cpp Database/PostgreSql/PostgreSqlDatabasePatcher.h
        Database/AbstractDatabasePatcher.cpp Database/AbstractDatabasePatcher.h
        Database/AbstractQueryValue.cpp Database/AbstractQueryValue.h
        Logs/AbstractLogger.cpp Logs/AbstractLogger.h
        Logs/ConsoleLogger.cpp Logs/ConsoleLogger.h
        Database/PostgreSql/PostgreSqlQueryValue.cpp Database/PostgreSql/PostgreSqlQueryValue.h
        Core/Uuid.cpp Core/Uuid.h
        Core/AbstractRandomGenerator.cpp Core/AbstractRandomGenerator.h
        Core/RandomGenerator.cpp Core/RandomGenerator.h Core/IStringable.h Database/PostgreSql/Patches/CreateProductsPatch.cpp Database/PostgreSql/Patches/CreateProductsPatch.h)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PostgreSQL_LIBRARIES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GTKMM3_LIBRARIES})


