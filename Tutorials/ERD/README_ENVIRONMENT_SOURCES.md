# DBMS Environment Project Source Guide

This file is a team-ready source guide for the new environment-based DBMS project.

The safest approach is:

1. Use **official Bangladesh government data** as the main source.
2. Use **international or research data** only for validation, comparison, or extra attributes.
3. Keep the raw data in **multiple Excel files** if needed, then normalize them into tables for the ERD and SQL part.

Multiple Excel files are completely fine for this project. In fact, that will usually make the data cleaner and easier to present.

## Recommended First Choice

If the team wants the most practical and safest option, start with:

1. [BBS Time Series Environmental Database.xlsx](http://203.112.218.101/storage/files/1/Publications/ECDS/Time%20Series%20Env.%20Database.xlsx)
2. [BRRI Climate Database page](https://www.brri.gov.bd/site/page/2ded3c9f-593b-4434-9dda-20e6f77d47ab/%E0%A6%9C%E0%A6%B2%E0%A6%AC%E0%A6%BE%E0%A7%9F%E0%A7%81%E0%A6%B0-%E0%A6%A1%E0%A6%BE%E0%A6%9F%E0%A6%BE%E0%A6%AC%E0%A7%87%E0%A6%9C)
3. [DoE Surface and Ground Water Quality Report 2023](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-doe/2024/12/1cd36972b14549859d16e9b460496d56.pdf)
4. [DoE Ambient Air Quality in Bangladesh (2018-2023)](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-doe/2024/12/014a6e225cf849098389d835538afdc9.pdf)

These four together are enough to design a strong ERD and show multiple Excel-based source files.

## 1. Climate and Weather Data

- **BBS Time Series Environmental Database**: [Direct XLSX](http://203.112.218.101/storage/files/1/Publications/ECDS/Time%20Series%20Env.%20Database.xlsx). Format: `XLSX`. You can find station-wise monthly maximum and minimum temperature, rainfall, humidity, wind speed, wind direction, sunshine, solar radiation, and thunderstorm/lightning frequency. This is the best single spreadsheet for building `station`, `climate_parameter`, and `climate_observation` tables.

- **Bangladesh Climate Database on data.gov.bd**: [Dataset page](https://data.gov.bd/dataset/bangladesh-climate-database), [resource page](https://data.gov.bd/bn/dataset/bangladesh-climate-database/resource/9545e597-2708-4453-8f2c-c97cd75b08d2). Format: government portal pointing to downloadable files. You can find official climate data coverage described for daily maximum temperature, minimum temperature, humidity, rainfall, sunshine, and related climate variables. This is useful as an official directory and validation source.

- **BRRI Climate Database**: [BRRI climate page](https://www.brri.gov.bd/site/page/2ded3c9f-593b-4434-9dda-20e6f77d47ab/%E0%A6%9C%E0%A6%B2%E0%A6%AC%E0%A6%BE%E0%A7%9F%E0%A7%81%E0%A6%B0-%E0%A6%A1%E0%A6%BE%E0%A6%9F%E0%A6%BE%E0%A6%AC%E0%A7%87%E0%A6%9C). Format: `XLSX`, `XLS`, `PDF`. You can find daily climate files and several location-based climate sheets. This is one of the best direct-download sources for climate data that can go straight into Excel.

- **BRRI Daily Maximum Temperature**: [XLSX download](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-brri/2024/12/4f0ba62449f948cf8f341b2ba69557bf.xlsx). Format: `XLSX`. You can find daily maximum temperature values by station and date.

- **BRRI Daily Minimum Temperature**: [XLSX download](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-brri/2024/12/1024daca0b8f4977bba1a17ebe49d6c4.xlsx). Format: `XLSX`. You can find daily minimum temperature values by station and date.

- **BRRI Daily Average Humidity**: [XLSX download](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-brri/2024/12/faf4e6a6efb84f30a771b19dd575856f.xlsx). Format: `XLSX`. You can find daily humidity values by station and date.

- **BRRI Daily Sunshine**: [XLSX download](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-brri/2024/12/1ee152e92d1045efae11db2a876f111a.xlsx). Format: `XLSX`. You can find daily sunshine duration values by station and date.

- **BRRI Daily Total Rainfall**: [XLSX download](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-brri/2024/12/8f2ae77dc96142be898d09052c5436f6.xlsx). Format: `XLSX`. You can find daily rainfall values by station and date.

- **Bangladesh Meteorological Department climate portal**: [BMD climate page](https://live8.bmd.gov.bd/en/climate), [Temperature data](https://live8.bmd.gov.bd/p/Temperature-Data), [Sunshine](https://live8.bmd.gov.bd/p/Sunshine), [Monthly maximum temperature](https://live8.bmd.gov.bd/p/Monthly-Maximum-Temperature), [Monthly minimum temperature](https://live8.bmd.gov.bd/p/Monthly-Minimum-Temperature), [Normal monthly rainfall](https://live8.bmd.gov.bd/p/Normal-Monthly-Rainfall). Format: official portal and downloadable files. You can find climate normals, station summaries, and climate reference tables. This is a strong official source for validation and extra monthly tables.

- **BMD downloadable climate PDFs**: [Normal max temperature PDF](https://live8.bmd.gov.bd/file/2016/08/17/pdf/50.pdf), [Normal min temperature PDF](https://live8.bmd.gov.bd/file/2016/08/17/pdf/51.pdf), [Normal rainfall PDF](https://live8.bmd.gov.bd/file/2016/08/17/pdf/53.pdf), [Historical temperature PDF](https://live8.bmd.gov.bd/file/2016/08/17/pdf/58.pdf). Format: `PDF`. You can find station-based climate tables that can be manually converted into Excel for a cleaner climate-only workbook.

- **BMD data request portal**: [dataportal.bmd.gov.bd](https://dataportal.bmd.gov.bd/). Format: official data access portal. You can find more formal historical weather data access if the team needs additional official records beyond the public downloads.

- **Daily Rainfall Data on data.gov.bd**: [Dataset link](https://data.gov.bd/dataset/daily-rainfall-data). Format: open data portal. You can find another official route for rainfall data that may help with backup or comparison.

- **Climate Information Management System on data.gov.bd**: [Dataset link](https://data.gov.bd/dataset/climate-information-management-system). Format: government portal. You can find additional climate-related resources and references.

## 2. Air Quality Data

- **DoE Ambient Air Quality in Bangladesh (2018-2023)**: [Publication page](https://doe.gov.bd/site/publications/a670df2d-0302-4acd-93e1-37a165eb5abf/Ambient-Air-Quality-In-bd-2018-2023), [direct PDF](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-doe/2024/12/014a6e225cf849098389d835538afdc9.pdf). Format: `PDF`. You can find AQI and pollutant information from 31 monitoring sites in 23 districts, including PM2.5, PM10, NOx, SO2, O3, CO, and some meteorological variables. This is the strongest official air-quality source for ERD design.

- **DoE Monthly AQI archive**: [Monthly AQI page](https://doe.gov.bd/pages/static-pages/6922de32933eb65569e18f46). Format: report archive. You can find monthly air-quality reports that can be converted into Excel tables such as `city`, `month`, `AQI`, and `pollutant_summary`.

- **DoE Daily AQI page**: [Daily AQI link](https://doe.gov.bd/site/page/8efde0a3-392e-4a86-bac4-7149ff908be7/). Format: daily reporting page. You can find frequent AQI updates and station or city-level air-quality information useful for recent samples.

- **Mendeley Bangladesh AQI Dataset**: [Dataset link](https://data.mendeley.com/datasets/9j447cynb9/2). Format: research dataset. You can find a very large historical hourly air-quality dataset across Bangladeshi cities with AQI and pollutant columns. This is useful only as a secondary source if your teacher accepts non-government research data.

## 3. Water Quality, Rivers, Flood, and Hydrology

- **DoE Surface and Ground Water Quality Report 2023**: [Publication page](https://doe.gov.bd/site/publications/da1b687c-2137-4db2-a0fd-0ea32b5fadba/Surface-and-Ground-Water-Quality-Report-2023), [direct PDF](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-doe/2024/12/1cd36972b14549859d16e9b460496d56.pdf). Format: `PDF`. You can find data from 102 river points, 3 lakes, and 63 groundwater stations with parameters like pH, EC, TDS, DO, BOD, COD, SS, chloride, turbidity, total alkalinity, and salinity. This is the best official water-quality source for tables such as `river`, `sampling_point`, `parameter`, and `water_observation`.

- **DoE water quality archive**: [Water quality archive page](https://doe.gov.bd/pages/static-pages/6922dca1933eb65569e115ac). Format: report archive. You can find more water-quality publications that may help if the team wants to compare years.

- **BWDB BRIMS**: [BRIMS home](https://nodi.bwdb.gov.bd/), [River info](https://nodi.bwdb.gov.bd/RiverInfo), [shapefile export](https://nodi.bwdb.gov.bd/Export/DdynamicRiverFile). Format: web database and shapefile export. You can find river names, river locations, mapping resources, and river-related reference data. This is excellent for `river`, `district`, and spatial reference tables.

- **BWDB Hydrology portal**: [Hydrology portal](https://www.hydrology.bwdb.gov.bd/). Format: official hydrology system. You can find water level, river station, and hydrological information that can support flood and river-monitoring projects.

- **Flood Forecasting and Warning Centre**: [FFWC](https://ffwc.bwdb.gov.bd/). Format: official flood and water level portal. You can find forecast points, water level information, and flood-related monitoring data. This is useful for tables like `forecast_station`, `water_level`, `warning_status`, and `observation_date`.

## 4. Land, Forest, Protected Area, Salinity, and Disaster Data

- **BBS Time Series Environmental Database**: [Direct XLSX](http://203.112.218.101/storage/files/1/Publications/ECDS/Time%20Series%20Env.%20Database.xlsx). Format: `XLSX`. You can also find land cover, wetlands, standing water bodies, salinity, river erosion, acidification, ecosystem area, forest area, protected areas, ecological critical areas, flood-affected area, cyclone-affected area, saline-prone area, cyclone shelters, arsenic contamination, and other environmental indicators. This makes it perfect for a multi-topic environmental ERD.

- **Bangladesh Forest Information System**: [BFIS e-Library](https://bfis.bforest.gov.bd/library/). Format: report and library portal. You can find forest-related reports, protected-area references, and background data that help build forest and protected-area entities.

- **State of Bangladesh's Forest Protected Areas**: [Report link](https://bfis.bforest.gov.bd/library/state-of-bangladeshs-forest-protected-areas/). Format: report. You can find protected-area names, categories, and forest-management context. This is useful for enrichment of `protected_area`, `forest_zone`, or `management_type` tables.

## 5. Household and General Environment Data

- **BBS Environment and Climate Change page**: [BBS ECDS page](https://bbs.gov.bd/site/page/76c9d52f-0a19-4563-99aa-9f5737bbd0d7/Environment--Climate-Change-%26-), [ECDS About](https://ecds.bbs.gov.bd/Home/AboutUs). Format: government portal. You can find the official Bangladesh environmental statistics portal, report links, GIS/admin resources, and the main publication hub.

- **BBS Household Based Environmental Survey 2024**: [HBES 2024 PDF](http://203.112.218.101/storage/files/1/Publications/ECDS/HBES_2024_13-7-25.pdf). Format: `PDF`. You can find data related to drinking water source, sanitation, waste disposal, cooking fuel, environmental awareness, mosquito prevention, tree planting, and household environmental practices. This is strong if the project focuses on people, households, or environmental behavior instead of climate stations.

- **Other BBS environmental publications via the ECDS page**: [BBS ECDS page](https://bbs.gov.bd/site/page/76c9d52f-0a19-4563-99aa-9f5737bbd0d7/Environment--Climate-Change-%26-). Format: reports and spreadsheets. You can find Bangladesh Environment Statistics 2024, Physical Flow Water Accounts, Natural Resources Accounts for Land, Natural Resources Accounts for Forest and Ecosystem, Material Footprint and Domestic Material Consumption, Environmental Protection Expenditure and Resource/Waste Management Survey 2022, and Municipal Waste Management Survey 2022. These are useful when the team wants official summary statistics by year, district, or sector.

## 6. Policy and Reference Sources

- **Ministry of Environment, Forest and Climate Change**: [MoEFCC main site](https://moef.gov.bd/), [documents page](https://moef.gov.bd/pages/static-pages/%E0%A6%A1%E0%A6%95%E0%A7%81%E0%A6%AE%E0%A7%87%E0%A6%A8%E0%A7%8D%E0%A6%9F%E0%A6%B8-e93af6-694032ba35ce18e1c056150e). Format: official policy and publication portal. You can find policy documents such as BCCSAP, National Air Quality Management Plan, climate and conservation reports, and ministry-level references. This is not the best raw data source, but it is very useful for the report introduction, motivation, and definitions.

## 7. International and Supporting Sources

- **World Bank Climate Change Knowledge Portal**: [Bangladesh overview](https://climateknowledgeportal.worldbank.org/country/bangladesh), [historical climate data](https://climateknowledgeportal.worldbank.org/country/bangladesh/climate-data-historical). Format: international climate portal. You can find national and subnational temperature and precipitation summaries, historical time series, and downloadable climate data views. This is good for validation and comparison, not as the primary source.

- **World Bank Bangladesh Country Environmental Analysis 2023**: [Report page](https://www.worldbank.org/en/region/sar/publication/bangladesh-country-environment-analysis-2023). Format: analytical report. You can find problem framing, important indicators, and context for report writing. This is best for literature review and project justification.

- **PoribeshBid Environmental Data Catalogue**: [Catalogue page](https://www.poribeshbid.org.bd/environmental-data-catalogue/). Format: curated directory. You can find links to many Bangladesh environmental data portals. This is useful for source discovery, but not as the main raw dataset.

- **Bangladesh Environmental Data Analysis GitHub repository**: [GitHub link](https://github.com/oRaqzz/Bangladesh-Environmental-Data-Analysis). Format: GitHub project. You can find a combined environment-style dataset and analysis idea. This is useful for inspiration only. It should not be used as the main source unless every field is traced back to an official origin.

## Best Sources by Use Case

### If the team wants the safest official-only project

1. [BBS Time Series Environmental Database.xlsx](http://203.112.218.101/storage/files/1/Publications/ECDS/Time%20Series%20Env.%20Database.xlsx)
2. [DoE Surface and Ground Water Quality Report 2023](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-doe/2024/12/1cd36972b14549859d16e9b460496d56.pdf)

### If the team wants a climate-focused project

1. [BBS Time Series Environmental Database.xlsx](http://203.112.218.101/storage/files/1/Publications/ECDS/Time%20Series%20Env.%20Database.xlsx)
2. [BRRI Climate Database page](https://www.brri.gov.bd/site/page/2ded3c9f-593b-4434-9dda-20e6f77d47ab/%E0%A6%9C%E0%A6%B2%E0%A6%AC%E0%A6%BE%E0%A7%9F%E0%A7%81%E0%A6%B0-%E0%A6%A1%E0%A6%BE%E0%A6%9F%E0%A6%BE%E0%A6%AC%E0%A7%87%E0%A6%9C)
3. [BMD climate portal](https://live8.bmd.gov.bd/en/climate)
4. [World Bank CCKP](https://climateknowledgeportal.worldbank.org/country/bangladesh)

### If the team wants an air-pollution project

1. [DoE Ambient Air Quality in Bangladesh (2018-2023)](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-doe/2024/12/014a6e225cf849098389d835538afdc9.pdf)
2. [DoE Monthly AQI archive](https://doe.gov.bd/pages/static-pages/6922de32933eb65569e18f46)
3. [Mendeley AQI dataset](https://data.mendeley.com/datasets/9j447cynb9/2) as secondary only

### If the team wants a water and river project

1. [DoE Surface and Ground Water Quality Report 2023](https://objectstorage.ap-dcc-gazipur-1.oraclecloud15.com/n/axvjbnqprylg/b/V2Ministry/o/office-doe/2024/12/1cd36972b14549859d16e9b460496d56.pdf)
2. [BWDB BRIMS](https://nodi.bwdb.gov.bd/)
3. [FFWC](https://ffwc.bwdb.gov.bd/)

## Suggested Excel Split

These are good workbook ideas if the team wants to keep the raw data organized before creating the ERD:

1. **`01_reference.xlsx`**: divisions, districts, upazilas, climate stations, air stations, rivers, lakes, parameters, pollutants, protected-area types.
2. **`02_climate.xlsx`**: daily temperature, daily rainfall, humidity, sunshine, monthly climate summaries, station metadata.
3. **`03_water_quality.xlsx`**: river list, sampling points, groundwater stations, water-quality parameters, yearly or monthly observations.
4. **`04_air_quality.xlsx`**: AQI records, city or station list, pollutant list, monthly summaries, daily observations.
5. **`05_land_forest_disaster.xlsx`**: land cover, forest area, protected areas, salinity, erosion, flood, cyclone, arsenic, wetland information.
6. **`06_household_environment.xlsx`**: water source, sanitation, waste disposal, fuel use, awareness, tree planting, mosquito prevention.

## ERD Ideas That Fit These Sources

### Option 1: Climate Monitoring Database

Possible core tables:

1. `division`
2. `district`
3. `station`
4. `climate_parameter`
5. `climate_observation`
6. `climate_normal`

Best source combination:

1. BBS Time Series
2. BRRI climate files
3. BMD climate tables

### Option 2: Water Quality Monitoring Database

Possible core tables:

1. `river`
2. `lake`
3. `groundwater_station`
4. `sampling_point`
5. `water_parameter`
6. `water_observation`

Best source combination:

1. DoE Water Quality Report
2. BWDB BRIMS
3. FFWC

### Option 3: Environmental Indicators Database

Possible core tables:

1. `district`
2. `year`
3. `indicator_type`
4. `indicator_value`
5. `protected_area`
6. `land_cover`
7. `disaster_event`

Best source combination:

1. BBS Time Series
2. BBS environmental publications
3. BRRI climate files
4. DoE air or water reports for enrichment

## Final Recommendation

For a clean DBMS submission, the easiest path is to choose **one main theme** instead of trying to store every environmental topic in one database.

The best three practical themes are:

1. **Climate database**
2. **Water quality database**
3. **Environmental indicators database by district/year**

If the team wants the least risky and most presentable choice, use **BBS Time Series + BRRI Climate + DoE Water** and keep them in separate Excel files before normalization.
