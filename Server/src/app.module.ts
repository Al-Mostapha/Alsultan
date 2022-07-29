import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { CityArmyAModel, CityArmyBModel, CityArmyCModel, CityArmyDModel, CityArmyEModel, CityArmyFModel, CityArmyTrapModel } from './Module/Army/CityArmy.model';
import { CityModule } from './Module/City/City.module';
import { CityBuildingFixedModel } from './Module/City/CityBuilding/CityBuildingFixed.model';
import { CityBuildingInnerModel } from './Module/City/CityBuilding/CityBuildingInner.model';
import { CityBuildingOuterModel } from './Module/City/CityBuilding/CityBuildingOuter.model';
import { CityResourceModel } from './Module/City/CityResource/CityResource.model';

@Module({
  imports: [
    TypeOrmModule.forRoot({
      type: 'mysql',
      host: 'localhost',
      port: 3306,
      username: 'root',
      password: '',
      database: 'alsultan',
      entities: [
        CityBuildingInnerModel,
        CityBuildingOuterModel,
        CityBuildingFixedModel,
        CityArmyAModel,
        CityArmyBModel,
        CityArmyCModel,
        CityArmyDModel,
        CityArmyEModel,
        CityArmyFModel,
        CityArmyTrapModel,
        CityResourceModel
      ],
      synchronize: true,
      logger: "advanced-console"
    }),
    CityModule,
  ],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule { }
