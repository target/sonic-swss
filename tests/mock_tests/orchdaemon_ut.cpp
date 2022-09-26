#include "orchdaemon.h"
#include "dbconnector.h"
#include <gtest/gtest.h>
//#include <gmock/gmock.h>
//#include "mock_sai_switch.h"

namespace orchdaemon_test
{
    DBConnector appl_db("APPL_DB", 0);
    DBConnector state_db("STATE_DB", 0);
    DBConnector config_db("CONFIG_DB", 0);
    DBConnector counters_db("COUNTERS_DB", 0);
    DBConnector *gAppDb = &appl_db;
    DBConnector *gStateDb = &state_db;
    DBConnector *gConfigDb = &config_db;
    DBConnector *gCountersDb = &counters_db;

    struct OrchDaemonTest : public ::testing::Test
    {
        protected:
//            StrictMock<MockSaiSwitch> mock_sai_switch_;

            OrchDaemon* orchd;

            OrchDaemonTest()
            {
//                mock_sai_switch = &mock_sai_switch_;

                orchd = new OrchDaemon(gAppDb, gConfigDb, gStateDb, gCountersDb);

//                orchd = new OrchDaemon(appl_db, config_db, state_db, counters_db);
            };

            ~OrchDaemonTest()
            {

            };
    };

    TEST_F(OrchDaemonTest, logRotate)
    {
//        EXPECT_CALL(mock_sai_switch_, set_switch_attribute( _, _)).WillOnce(Return(SAI_STATUS_SUCCESS));
        EXPECT_NO_THROW(orchd->logRotate());
    }
}
